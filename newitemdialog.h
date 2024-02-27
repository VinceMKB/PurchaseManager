#ifndef NEWITEMDIALOG_H
#define NEWITEMDIALOG_H

#include <QDialog>

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
};

#endif // NEWITEMDIALOG_H
