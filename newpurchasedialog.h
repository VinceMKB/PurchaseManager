#ifndef NEWPURCHASEDIALOG_H
#define NEWPURCHASEDIALOG_H

#include <QDialog>

namespace Ui {
class newPurchaseDialog;
}

class newPurchaseDialog : public QDialog
{
    Q_OBJECT

public:
    explicit newPurchaseDialog(QWidget *parent = nullptr);
    ~newPurchaseDialog();

private:
    Ui::newPurchaseDialog *ui;
};

#endif // NEWPURCHASEDIALOG_H
