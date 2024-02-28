#include "newitemdialog.h"
#include "ui_newitemdialog.h"

newItemDialog::newItemDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::newItemDialog)
{
    ui->setupUi(this);

    connect(ui->buttonAddItem, &QPushButton::clicked, this, &newItemDialog::addItem);
    connect(ui->buttonDone, &QPushButton::clicked, this, &newItemDialog::done);
}

newItemDialog::~newItemDialog()
{
    delete ui;
}

void newItemDialog::addItem()
{
    QString resourceTxtFile = ":/resources/ItemList.txt";

    QString newItemType = ui->comboBoxItemType->currentText();
    QString newItemName = ui->lineEditItemName->text();

    //Validation Check, so every field is filled in.
    if(newItemType.isEmpty()|| newItemName.isEmpty())
    {
        QMessageBox::warning(this, "INPUT ERROR", "Please fill in all the fields.");
        return;
    }

    QFile file(resourceTxtFile);
    if(file.open(QIODevice::Append | QIODevice::Text))
    {
        QTextStream out(&file);
        out << newItemName << " - " << newItemType << "\n";
        file.close();
    }
    else
    {
        QMessageBox::critical(this, "Error", "Could not write to the file.");
    }

}

void newItemDialog::done()
{
    this->close();
}
