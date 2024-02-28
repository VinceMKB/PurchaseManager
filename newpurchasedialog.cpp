#include "newpurchasedialog.h"
#include "ui_newpurchasedialog.h"

newPurchaseDialog::newPurchaseDialog(QStandardItemModel *npd_model, QWidget *parent)
    :QDialog(parent)
    ,ui(new Ui::newPurchaseDialog)
    ,npd_treemodel(npd_model)
{
    ui->setupUi(this);

    //Initializing QStringListModel
    npd_listmodel = new QStringListModel(this);
    ui->listView->setModel(npd_listmodel);

    //Set default values and minimum values for StockQuantituSpinBox
    ui->spinBoxQuantity->setValue(1);
    ui->spinBoxQuantity->setMinimum(1);

    QString resourceTxtFile = ":/resources/ItemList.txt";

    QFile file(resourceTxtFile);
    if(file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream in(&file);
        while(!in.atEnd())
        {
            QString line = in.readLine();
            QStringList  parts = line.split(" - ");
            if(parts.size() == 2)
            {
                ui->comboBoxItemInStock->addItem(line);
            }
        }
        file.close();
    }

    connect(ui->buttonAddPuchase, &QPushButton::clicked, this, &newPurchaseDialog::addPurchase);
    connect(ui->buttonCheckOut, &QPushButton::clicked, this, &newPurchaseDialog::checkout);
}

newPurchaseDialog::~newPurchaseDialog()
{
    delete ui;
}

void newPurchaseDialog::addPurchase()
{
    //Getting input of the fields
    QString customerName = ui->lineEditCustomerName->text();
    QString stocktypeName = ui->comboBoxItemInStock->currentText();
    int stockQuantity = ui->spinBoxQuantity->value();

    //Validation Check. Did not check stockQuantity since I set the default value and minimum value already
    if(customerName.isEmpty()|| stocktypeName.isEmpty())
    {
        QMessageBox::warning(this, "INPUT ERROR", "Please fill in all the fields correctly.");
        return;
    }

    //Getting Current System time and date
    QDateTime currentDateTime = QDateTime::currentDateTime();

    //Update the QStringListModel
    QStringList currentlist = npd_listmodel->stringList();
    currentlist << QString("%1 - %2").arg(stocktypeName).arg(stockQuantity);
    npd_listmodel->setStringList(currentlist);

    //Insert values into QTreeView
    QStandardItem *customerItem = nullptr;
    for(int i = 0; i < npd_treemodel->rowCount(); ++i)
    {
        if(npd_treemodel->item(i)->text() == customerName)
        {
            customerItem = npd_treemodel->item(i);
            break;
        }
    }

    if(!customerItem)
    {
        customerItem = new QStandardItem(customerName);
        npd_treemodel->appendRow(customerItem);
    }

    QStandardItem *datetimeItem = new QStandardItem(currentDateTime.toString("yyyy-MM-dd HH:mm"));
    customerItem->appendRow(datetimeItem);

    //Splits stocktypeName into parts
    QStringList parts = stocktypeName.split(" - ");
    QString purchaseType = parts[0];
    QString itemType = parts[1];

    QStandardItem *purchaseTypeItem = new QStandardItem(purchaseType);
    QStandardItem *itemTypeItem = new QStandardItem(itemType);
    QStandardItem *stockQuantityItem = new QStandardItem(QString::number(stockQuantity));

    qDebug() << "StockQuantity: " << stockQuantity;
    qDebug() << "StockQuantityItem: " << stockQuantityItem;

    datetimeItem->appendRow({purchaseTypeItem, itemTypeItem, stockQuantityItem});

}

void newPurchaseDialog::checkout()
{
    this->close();
}


