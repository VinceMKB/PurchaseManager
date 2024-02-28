#ifndef NEWPURCHASEDIALOG_H
#define NEWPURCHASEDIALOG_H

#include <QDialog>
#include <QStandardItemModel>
#include <QStringListModel>
#include <QFile>
#include <QTextStream>
#include <QDateTime>
#include <QMessageBox>

namespace Ui {
class newPurchaseDialog;
}

class newPurchaseDialog : public QDialog
{
    Q_OBJECT

public:
    explicit newPurchaseDialog(QStandardItemModel *npd_model, QWidget *parent = nullptr);
    ~newPurchaseDialog();

private:
    Ui::newPurchaseDialog *ui;

    QStandardItemModel *npd_treemodel;//npd = NewPurchaseDialog
    QStringListModel *npd_listmodel;//npd = NewPurchaseDialog

private slots:
    void addPurchase();
    void checkout();
};

#endif // NEWPURCHASEDIALOG_H
