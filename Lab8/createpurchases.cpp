#include "login_db.h"
#include <QMessageBox>
#include "createpurchases.h"
#include "ui_createpurchases.h"

CreatePurchases::CreatePurchases(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreatePurchases)
{
    ui->setupUi(this);
}

CreatePurchases::~CreatePurchases()
{
    delete ui;
}

void CreatePurchases::on_pushButton_Add_clicked()
{
    int productQuantity = 0;    //Number of products purchased

    double itemPrice = 0;       //Price of the item

    ExecutiveMember exec;       //ExecutiveMember class, used to represent either execuitives or regulars
    QSqlQuery query, query2, query3;    //acceses customers, acceses inventory, acceses customerPurchases

    QString date, itemName, customerNumber, membership, membershipRenewal, temp; //Date of purchase, name of product,
                                                                                 //customer ID, membership type, membership
                                                                                 //renewal date, temporary value


    //INPUT - Gets Quantity, name, ID, and date of purchase
    productQuantity = ui->edit_Quantity->text().toInt();
    itemName = ui->edit_Name->text();
    customerNumber = ui->edit_Number->text();
    date = ui->edit_Date->text();

    //INPUT - customer data
    query.prepare("select * from customers");
    if(!query.exec())
    {
        qDebug() << "ERROR " << query.lastError();
    }

    while(query.next())
    {
        temp = query.value(2).toString();   //temporary variable get ID

        //Debugging
        qDebug() << "This is the input ID" << customerNumber;
        qDebug() << "This is the current ID" << temp;

        if(temp == customerNumber)
        {
          //Debugging
          //qDebug() << "I'm Here " << index;

          exec.setFirstName(query.value(0).toString());
          exec.setLastName(query.value(1).toString());
          exec.setID(query.value(2).toString());
          membership = query.value(3).toString();
          membershipRenewal = query.value(4).toString();
        }
     }

    //INPUT - product data
    query2.prepare("select * from inventory");
    if(!query2.exec())
    {
        qDebug() << "ERROR " << query2.lastError();
    }

    while(query2.next())
    {
        QString variable = query2.value(0).toString();   //temporary variable itemName

        //Debugging
        qDebug() << "This is the input product" << itemName;
        qDebug() << "This is the current product" << variable;

        if(variable == itemName)
        {
          bool variable2 = query2.value(2).toBool(); //temporary variable to test if item is in stock

          //tests if product is in stock
          if(variable2)
          {
              //Debugging
              qDebug() << "Is the item in stock: " << variable2;

              itemPrice = query2.value(1).toDouble();
          }
          else
          {
              QMessageBox::critical(this,tr("Error"), "This item is out of stock!");
          }
        }
     }

    //Inserts data to customerPurchases
    query3.prepare("INSERT INTO customerPurchases (date, firstName, lastName, customerNumber, membership, productName, productPrice, productQuantity, renewalDate)"
                "VALUES (:date, :firstName, :lastName, :customerNumber, :membership, :productName, :productPrice, :productQuantity, :renewalDate)");
    query3.bindValue(":date", date);
    query3.bindValue(":firstName", exec.getFirstName());
    query3.bindValue(":lastName", exec.getLastName());
    query3.bindValue(":customerNumber", exec.getID());
    query3.bindValue(":membership", membership);
    query3.bindValue(":productName", itemName);
    query3.bindValue(":productPrice", itemPrice);
    query3.bindValue(":productQuantity", productQuantity);
    query3.bindValue(":renewalDate", membershipRenewal);

    if(query3.exec())
    {
        QMessageBox::critical(this,tr("Add"),tr("Saved"));
    }
    else
    {
         QMessageBox::critical(this,tr("Error"),query3.lastError().text());
    }


}

void CreatePurchases::on_pushButton_Delete_clicked()
{
    int productQuantity = 0;    //Number of products purchased

    QString customerNumber, productName, date;     //ID of user, name of product, date of purchase

    //INPUT - Gets Quantity, name, ID, and date of purchase
    productQuantity = ui->edit_Quantity->text().toInt();
    productName = ui->edit_Name->text();
    customerNumber = ui->edit_Number->text();
    date = ui->edit_Date->text();

    QSqlQuery qry;  //access customerPurchases table
    qry.prepare("DELETE FROM customerPurchases WHERE date=? and customerNumber=? and productQuantity=? and productName=?");
    qry.addBindValue(date);
    qry.addBindValue(customerNumber);
    qry.addBindValue(productQuantity);
    qry.addBindValue(productName);

    //Deletes user
    if(qry.exec())
    {
        QMessageBox::critical(this,tr("Delete"),tr("Deleted"));
    }
    else
    {
         QMessageBox::critical(this,tr("Error"),qry.lastError().text());
    }
}
