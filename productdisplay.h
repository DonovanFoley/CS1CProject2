#ifndef PRODUCTDISPLAY_H
#define PRODUCTDISPLAY_H

#include <QDialog>
#include <string>
#include <QSqlDatabase>
#include "QSqlTableModel"
#include <QMessageBox>
#include <QSqlQuery>
#include <QTableWidget>
#include <QLabel>
#include <QString>
#include <QSqlQueryModel>
#include <QLineEdit>
#include <QListWidget>
#include <QDebug>

namespace Ui {
class ProductDisplay;
}

class ProductDisplay : public QDialog
{
    Q_OBJECT

public:
    explicit ProductDisplay(QWidget *parent = nullptr);
    ~ProductDisplay();

    ProductDisplay(const ProductDisplay &test);
    ProductDisplay(QString names);

private slots:
    void on_pushButton_clicked();

private:
    Ui::ProductDisplay *ui;
    QSqlDatabase customers;
};

#endif // PRODUCTDISPLAY_H
