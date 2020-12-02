#ifndef CREATEPURCHASES_H
#define CREATEPURCHASES_H

#include <QDialog>

namespace Ui {
class CreatePurchases;
}

class CreatePurchases : public QDialog
{
    Q_OBJECT

public:
    explicit CreatePurchases(QWidget *parent = nullptr);
    ~CreatePurchases();

private slots:
    void on_pushButton_Add_clicked();

    void on_pushButton_Delete_clicked();

private:
    Ui::CreatePurchases *ui;
};

#endif // CREATEPURCHASES_H
