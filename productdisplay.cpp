#include "productdisplay.h"
#include "ui_productdisplay.h"

ProductDisplay::ProductDisplay(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ProductDisplay)
{
    ui->setupUi(this);

    //close database
    customers.close();
    customers.removeDatabase("first");

    QSqlDatabase customerDatabase = QSqlDatabase::addDatabase("QSQLITE", "first");
    customerDatabase.setDatabaseName("C:\\Users\\morer\\Documents\\GitHub\\bulkclubproject\\Bulk_Club1.db");//EDIT CODE HERE

    if (customerDatabase.open()) {
       // QMessageBox::information(this, "Database success", "Database Is Connected!");

        //Create query always pass database name into it
        QSqlQuery query(customerDatabase);


        //Prepare query, run values that you want to retrieve from table
        query.prepare(QString("SELECT * FROM customerPurchases "));
        query.exec("SELECT productName, SUM(productQuantity), SUM(productQuantity * productPrice) FROM customerPurchases GROUP BY productName ");

        //Error check
        if (!query.exec()) {
            QMessageBox::warning(this, "Fail", "Query did not execute in day 2");
        }
        else
        {

            double sum = 0;
            while(query.next())
            {
                QString date = query.value(0).toString();
                QString firstName = query.value(1).toString();
                QString lastName = query.value(2).toString();
                QString customerNumber = query.value(3).toString();
                QString membership = query.value(4).toString();
                QString productName = query.value(5).toString();
                double productPrice = query.value(6).toDouble();
                double productQuantity = query.value(7).toDouble();
                QString renewalDate = query.value(8).toString();

                sum = sum + (productPrice*productQuantity);
                QString sumString = QString::number(sum);
                sumString = "Total Revenue from Day 2: $" + sumString;

            }

            QSqlQueryModel *search = new QSqlTableModel;
            search->setQuery(query);
            ui->tableView->setModel(search);

        }
    }
}

ProductDisplay::~ProductDisplay()
{
    delete ui;
}

void ProductDisplay::on_pushButton_clicked()
{
    QString id = ui->lineEdit->text();

    customers.close();
    customers.removeDatabase("first");

    QSqlDatabase customerDatabase = QSqlDatabase::addDatabase("QSQLITE", "first");
    customerDatabase.setDatabaseName("C:\\Users\\morer\\Documents\\GitHub\\bulkclubproject\\Bulk_Club1.db");//EDIT CODE HERE

    if (customerDatabase.open()) {
       // QMessageBox::information(this, "Database success", "Database Is Connected!");

        //Create query always pass database name into it
        QSqlQuery query(customerDatabase);

        //Prepare query, run values that you want to retrieve from table
        query.prepare("SELECT  "
                      "    SUM(productprice * productquantity), "
                      "    SUM(productQuantity) "
                      "FROM  "
                      "    customerPurchases  "
                      "WHERE  "
                      "    productName = ?");
        query.addBindValue(id);

        //Error check
        if (!query.exec()) {
            qDebug() << "query falied";
            return;
        }

        if (query.next()) {
            // This will execute if we found a member
            float revenue = query.value(0).toFloat();
            float total = query.value(1).toFloat();

            // Then here you can update the display with revenue and firstName
            ui->lineEdit_2->setText(QString::number(total));
            ui->lineEdit_3->setText(QString::number(revenue, 'f', 2));

        }

    }
}
