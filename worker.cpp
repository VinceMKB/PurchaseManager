
#include "worker.h"

Worker::Worker(QStandardItemModel *w_model, QMutex &mutex, QObject *parent): QObject(parent), w_model(w_model), mutex(mutex)
{

}

void Worker::convertmodeltoXML(QStandardItem *w_item, QDomElement &element, QDomDocument &doc)
{
    QDomElement purchaseElement = doc.createElement("Purchase");
    purchaseElement.setAttribute("date", w_item->text());
    element.appendChild(purchaseElement);

    for(int i = 0; i<w_item->rowCount(); ++i)
    {
        QDomElement itemElement = doc.createElement("Item");

        //Name
        QStandardItem *childItem = w_item->child(i, 0);
        itemElement.setAttribute("Name", childItem ? childItem->text() : "");

        //Item type
        childItem = w_item->child(i, 1);
        itemElement.setAttribute("Type", childItem ? childItem->text() : "");

        //Quantity
        childItem = w_item->child(i,2);
        itemElement.setAttribute("Quantity", childItem ? childItem->text() : "");

        purchaseElement.appendChild(itemElement);
    }
}

void Worker::perform_worker()
{
    mutex.lock();

    QDomDocument doc("Purchases");
    QDomElement root = doc.createElement("Purchases");
    doc.appendChild(root);

    for (int i = 0; i < w_model->rowCount(); ++i)
    {
        QStandardItem *item = w_model->item(i);
        if (item == nullptr) continue;

        QDomElement customerElement = doc.createElement("customer");
        customerElement.setAttribute("name", item->text());
        root.appendChild(customerElement);

        for (int j = 0; j < item->rowCount(); ++j)
        {
            QStandardItem *purchaseItem = item->child(j);
            if (purchaseItem == nullptr) continue;

            convertmodeltoXML(purchaseItem, customerElement, doc);
        }
    }

    QByteArray xmlData = doc.toString(4).toUtf8();  // Indent by 4 spaces
    qint64 bytesSent = udpSocket.writeDatagram(xmlData, QHostAddress::LocalHost, 45454);
    if (bytesSent == -1)
    {
        qDebug() << "Could not send UDP datagram: " << udpSocket.errorString();
    }

    mutex.unlock();
}

