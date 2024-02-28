
#ifndef WORKER_H
#define WORKER_H

#include <QObject>
#include <QStandardItemModel>
#include <QMutex>
#include <QDomDocument>
#include <QUdpSocket>
#include <QDebug>



class Worker : public QObject
{
    Q_OBJECT
public:
    explicit Worker(QStandardItemModel *w_model, QMutex &mutex, QObject *parent=nullptr);
    void convertmodeltoXML(QStandardItem *w_item, QDomElement &element, QDomDocument &doc);

private:
    QStandardItemModel *w_model;
    QMutex &mutex;
    QUdpSocket udpSocket;

public slots:
    void perform_worker();
};

#endif // WORKER_H
