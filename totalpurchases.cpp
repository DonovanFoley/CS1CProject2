#include "totalpurchases.h"
#include "ui_totalpurchases.h"

totalPurchases::totalPurchases(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::totalPurchases)
{
    ui->setupUi(this);

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
        query.exec("SELECT customerNumber, firstName, lastName, SUM(productQuantity * productPrice) FROM customerPurchases GROUP BY customerNumber ");

        //Error check
        if (!query.exec()) {
           // QMessageBox::warning(this, "Fail", "Query did not execute");
        }
        else
        {

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
            }

            QSqlQueryModel *search = new QSqlTableModel;
            search->setQuery(query);
            ui->tableView->setModel(search);

        }
    }

}

totalPurchases::~totalPurchases()
{
    delete ui;
}

void totalPurchases::on_pushButton_clicked()
{
    QString id = ui->lineEdit->text();
    QString name = ui->lineEdit_3->text();
    QString lastName = ui->lineEdit_4->text();

    customers.close();
    customers.removeDatabase("first");

    QSqlDatabase customerDatabase = QSqlDatabase::addDatabase("QSQLITE", "first");
    customerDatabase.setDatabaseName("C:\\Users\\morer\\Documents\\GitHub\\bulkclubproject\\Bulk_Club1.db");//EDIT CODE HERE

    if (customerDatabase.open()) {
       // QMessageBox::information(this, "Database success", "Database Is Connected!");

        //Create query always pass database name into it
        QSqlQuery query(customerDatabase);

        if(id != "")
        {

        //Prepare query, run values that you want to retrieve from table
        query.prepare("SELECT  "
                      "    SUM(customerPurchases.productprice * customerPurchases.productquantity), "
                      "    customers.firstname "
                      "FROM  "
                      "    customers  "
                      "INNER JOIN  "
                      "    customerPurchases "
                      "ON  "
                      "    customers.id = customerPurchases.customernumber  "
                      "WHERE  "
                      "    customers.id = ? ");
        query.addBindValue(id);

        //Error check
        if (!query.exec()) {
            qDebug() << "query falied";
            return;
        }

        if (query.next()) {
            // This will execute if we found a member
            float revenue = query.value(0).toFloat();
            QString firstName = query.value(1).toString();

            // Then here you can update the display with revenue and firstName
            ui->lineEdit_2->setText(QString::number(revenue, 'f', 2));

        }//end if (query.next())

        }// end if(id != "")

        if(name != "")
        {
            //Prepare query, run values that you want to retrieve from table
            query.prepare("SELECT SUM(productprice * productquantity) FROM customerPurchases WHERE firstName = ? AND lastName = ?");
            query.addBindValue(name);
            query.addBindValue(lastName);

            //Error check
            if (!query.exec()) {
                qDebug() << "query falied from full name";
                return;
            }

            if (query.next()) {
                // This will execute if we found a member
                float revenue = query.value(0).toFloat();
                QString fullName = query.value(1).toString();

                ui->lineEdit_2->setText(QString::number(revenue, 'f', 2));

            }//end if (query.next())

        }

    }//end if (customerDatabase.open())


}
