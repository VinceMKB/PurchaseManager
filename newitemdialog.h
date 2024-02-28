#ifndef NEWITEMDIALOG_H
#define NEWITEMDIALOG_H

#include <QDialog>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>


namespace Ui {
class newItemDialog;
}

class newItemDialog : public QDialog
{
    Q_OBJECT

public:
    explicit newItemDialog(QWidget *parent = nullptr);
    ~newItemDialog();

private:
    Ui::newItemDialog *ui;

private slots:
    void addItem();
    void done();

};

#endif // NEWITEMDIALOG_H
