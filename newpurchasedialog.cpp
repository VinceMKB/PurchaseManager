#include "newpurchasedialog.h"
#include "ui_newpurchasedialog.h"

newPurchaseDialog::newPurchaseDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::newPurchaseDialog)
{
    ui->setupUi(this);
}

newPurchaseDialog::~newPurchaseDialog()
{
    delete ui;
}
