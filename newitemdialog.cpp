#include "newitemdialog.h"
#include "ui_newitemdialog.h"

newItemDialog::newItemDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::newItemDialog)
{
    ui->setupUi(this);
}

newItemDialog::~newItemDialog()
{
    delete ui;
}
