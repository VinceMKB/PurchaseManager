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
    connect(ui->buttonAddPuchase, &QPushButton::clicked, this, &newPurchaseDialog::addPurchase);
}

newPurchaseDialog::~newPurchaseDialog()
{
    delete ui;
}
