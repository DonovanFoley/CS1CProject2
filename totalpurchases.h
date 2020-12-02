#ifndef TOTALPURCHASES_H
#define TOTALPURCHASES_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QDebug>

namespace Ui {
class totalPurchases;
}

class totalPurchases : public QDialog
{
    Q_OBJECT

public:
    explicit totalPurchases(QWidget *parent = nullptr);
    ~totalPurchases();

private slots:
    void on_pushButton_clicked();

private:
    Ui::totalPurchases *ui;
    QSqlDatabase customers;

};

#endif // TOTALPURCHASES_H
