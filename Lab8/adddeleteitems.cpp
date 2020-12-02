#include "login_db.h"
#include <QMessageBox>
#include "adddeleteitems.h"
#include "ui_adddeleteitems.h"

AddDeleteItems::AddDeleteItems(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddDeleteItems)
{
    ui->setupUi(this);
}

AddDeleteItems::~AddDeleteItems()
{
    delete ui;
}

void AddDeleteItems::on_pushButton_Add_clicked()
{

    QString itemName;     //name of product
    double itemPrice;     //price of product

    //Input data
    itemName=ui->edit_Name->text();
    itemPrice=ui->edit_Price->text().toDouble();

    QSqlQuery qry;  //access inventory table
    qry.prepare("INSERT INTO inventory (itemName, itemPrice, inStock)"
                "VALUES (:itemName, :itemPrice, :inStock)");
    qry.bindValue(":itemName", itemName);
    qry.bindValue(":itemPrice", itemPrice);

    if(inStock)
    {
        qry.bindValue(":inStock", "Yes");
    }
    else
    {
        qry.bindValue(":inStock", "No");
    }
    //qry.exec();

    if(qry.exec())
    {
        QMessageBox::critical(this,tr("Add"),tr("Saved"));
    }
    else
    {
         QMessageBox::critical(this,tr("Error"),qry.lastError().text());
    }
}

void AddDeleteItems::on_pushButton_Delete_clicked()
{
    QString itemName;     //name of the item

    //INPUT - Name of item
    itemName=ui->edit_Name->text();


    QSqlQuery qry;  //access cutomers table
    qry.prepare("Delete from inventory where itemName='"+itemName+"'");

    //Deletes item
    if(qry.exec())
    {
        QMessageBox::critical(this,tr("Delete"),tr("Deleted"));
    }
    else
    {
         QMessageBox::critical(this,tr("Error"),qry.lastError().text());
    }
}

void AddDeleteItems::on_radio_Stock_toggled(bool checked)
{
    //sets membership status
    if (checked)
    {
       inStock = true;
    }
    else
    {
        inStock = false;
    }
}

void AddDeleteItems::on_pushButton_Edit_clicked()
{
    //Deletes data to clear data
    QString itemName;     //name of the item

    //INPUT - Name of item
    itemName=ui->edit_Name->text();

    QSqlQuery qry;  //access cutomers table
    qry.prepare("Delete from inventory where itemName='"+itemName+"'");

    qry.exec();

    //Adds data to update data
    double itemPrice;     //price of product

    //Input data
    itemName=ui->edit_Name->text();
    itemPrice=ui->edit_Price->text().toDouble();

    QSqlQuery qry2;  //access inventory table
    qry2.prepare("INSERT INTO inventory (itemName, itemPrice, inStock)"
                "VALUES (:itemName, :itemPrice, :inStock)");
    qry2.bindValue(":itemName", itemName);
    qry2.bindValue(":itemPrice", itemPrice);

    if(inStock)
    {
        qry2.bindValue(":inStock", "Yes");
    }
    else
    {
        qry2.bindValue(":inStock", "No");
    }

    if(qry2.exec())
    {
        QMessageBox::critical(this,tr("Update"),tr("Updated"));
    }
    else
    {
         QMessageBox::critical(this,tr("Error"),qry2.lastError().text());
    }

}
