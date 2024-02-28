
#include "mainwindow.h"
#include "itemlistmemento.h"
#include "itemlistoriginator.h"
#include "newpurchasedialog.h"
#include "newitemdialog.h"
#include "worker.h"
#include "./ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    ,m_itemlistmemento(QStringList())
{
    ui->setupUi(this);

    //Setup for tree model
    mw_treemodel = new QStandardItemModel();
    mw_treemodel->setHorizontalHeaderLabels(QStringList() << "Purchase" << "Type" << "Quantity");
    ui->treeView->setModel(mw_treemodel);

    //Make columns divide evenly
    QHeaderView *header = ui->treeView->header();
    header->setStretchLastSection(false);
    header->setSectionResizeMode(QHeaderView::Stretch);

    //Increase font size and make header labels bold
    QFont font = header->font();
    font.setPointSize(12);
    font.setBold(true);
    header->setFont(font);

    //Setup menu connections
    connect(ui->actionAddPurchase, &QAction::triggered, this, &MainWindow::actionAddPurchase_Slot);
    connect(ui->actionAddItem, &QAction::triggered, this, &MainWindow::actionAddItem_Slot);
    connect(ui->actionRestoreItemList, &QAction::triggered, this, &MainWindow::actionrestoreItemList_Slot);

    //Setup menu connections
    workerthread = new QThread();
    Worker *worker = new Worker(mw_treemodel, modelmutex, this);
    worker->moveToThread(workerthread);

    //Connect signals and slots for worker
    connect(this, &MainWindow::dataAdded, worker, &Worker::perform_worker);
    connect(workerthread, &QThread::finished, worker, &QObject::deleteLater);

    //Start the worker thread
    workerthread->start();
}

MainWindow::~MainWindow()
{
    workerthread->quit();
    workerthread->wait();
    delete ui;
}

void MainWindow::actionAddPurchase_Slot()
{
    newPurchaseDialog dialog(mw_treemodel, this);
    dialog.exec();

    emit dataAdded();
}

void MainWindow::actionAddItem_Slot()
{
    QString resourceTxtFile = ":/resources/ItemList.txt";

    QFile file(resourceTxtFile);
    QStringList currentItemList;

    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream in(&file);
        while (!in.atEnd())
        {
            QString line = in.readLine();
            currentItemList.append(line);
        }
        file.close();
    }

    m_itemlistoriginator.setState(currentItemList);
    m_itemlistmemento = m_itemlistoriginator.savetoMemento();

    //Opening the Dialog
    newItemDialog dialog(this);
    dialog.exec();
}

void MainWindow::actionrestoreItemList_Slot()
{
    QString resourceTxtFile = ":/resources/ItemList.txt";

    m_itemlistoriginator.restorefromMemento(m_itemlistmemento);
    QStringList restore_ItemList = m_itemlistoriginator.getState();

    QFile file(resourceTxtFile);
    if(file.open(QIODevice::WriteOnly|QIODevice::Text))
    {
        QTextStream out(&file);
        for(const QString &line : restore_ItemList)
        {
            out << line << "\n";
        }
        file.close();
    }
    else
    {
        QMessageBox::critical(this, "ERROR", "Could not write to the file.");
    }
}




