#include "login_db.h"
#include "adddelete.h"
#include "ui_adddelete.h"
#include <QMessageBox>

AddDelete::AddDelete(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddDelete)
{
    ui->setupUi(this);
}

AddDelete::~AddDelete()
{
    delete ui;
}

void AddDelete::on_pushButton_Add_clicked()
{
    QString firstName, lastName, ID, membershipRenewal;     //represent the first name, last name, ID, and membership renewal date of a of a member
    double renewalPrice;                                    //price to renew membership

    firstName=ui->edit_FirstName->text();
    lastName=ui->edit_LastName->text();
    ID=ui->edit_Number->text();
    membershipRenewal=ui->edit_ExpDate->text();

    //CALC - Sets membership and price
    if(membership == "Executive")        //membership is stored within the header file, to allow button functionality
    {
        renewalPrice = 120.0;
    }
    else
    {
        membership = "Regular";
        renewalPrice = 65.0;
    }

    QSqlQuery qry;  //access customers table
    qry.prepare("INSERT INTO customers (firstName, lastName, ID, membership, membershipRenewal, renewalPrice)"
                "VALUES (:firstName, :lastName, :ID, :membership, :membershipRenewal, :renewalPrice)");
    qry.bindValue(":firstName", firstName);
    qry.bindValue(":lastName", lastName);
    qry.bindValue(":ID", ID);
    qry.bindValue(":membership", membership);
    qry.bindValue(":membershipRenewal", membershipRenewal);
    qry.bindValue(":renewalPrice", renewalPrice);
    qry.exec();

    if(!qry.exec())
    {
        QMessageBox::critical(this,tr("Add"),tr("Saved"));
    }
    else
    {
         QMessageBox::critical(this,tr("Error"),qry.lastError().text());
    }

}

void AddDelete::on_pushButton_Delete_clicked()
{

    QString ID;     //ID of user

    //INPUT - ID
    ID=ui->edit_Number->text();


    QSqlQuery qry;  //access cutomers table
    qry.prepare("Delete from customers where ID='"+ID+"'");

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

void AddDelete::on_radio_Executive_toggled(bool checked)
{
    //sets membership status
    if (checked)
    {
       membership = "Executive";
    }
    else
    {
        membership = "Regular";
    }
}
