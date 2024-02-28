
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "itemlistoriginator.h"

#include <QMainWindow>
#include <QStandardItemModel>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QDateTime>
#include <QMutex>
#include <QMessageBox>
#include <QDialog>
#include <QThread>



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow

{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QStandardItemModel *mw_treemodel;//mw = mainwindow

    //Mutex lock for threading
    QMutex modelmutex;

    ItemListOriginator m_itemlistoriginator;
    ItemListMemento m_itemlistmemento;

    //Thread
    QThread *workerthread;

private slots:
    void actionAddPurchase();
    void actionAddItem();
    void restoreItemList();

signals:
    void dataAdded();
};

#endif // MAINWINDOW_H
