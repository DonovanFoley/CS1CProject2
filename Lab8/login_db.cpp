#include "login_db.h"
#include "ui_login_db.h"
#include "displayrebate.h"
#include "expiringmembers.h"
#include "adddelete.h"
#include "adddeleteitems.h"
#include "createpurchases.h"
#include "displayitemssold.h"

Login_DB::Login_DB(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Login_DB)
{
    ui->setupUi(this);

    QSqlDatabase mydb=QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("E:/Qt/build-Lab8-Desktop_Qt_5_15_0_MinGW_64_bit-Debug/Bulk_Club.db");
    mydb.open();

    QSqlQuery query;

    query.prepare("select * from customers");
    if(!query.exec())
    {
        qDebug() << "ERROR " << query.lastError();
    }
    while(query.next())
    {
        QString variable = query.value(0).toString();

        QSqlQueryModel * modal=new QSqlQueryModel();
        modal->setQuery(query);
        ui->tableView->setModel(modal);
    }
}

Login_DB::~Login_DB()
{
    delete ui;
}

void Login_DB::on_pushButton_loadTable_clicked()
{
    QSqlQuery query; //qry=new QSqlQuery(mydb);

    query.prepare("select * from customers");
    if(!query.exec())
    {
        //qDebug() << "ERROR " << query.lastError().text;
    }
    while(query.next())
    {
        QString variable = query.value(0).toString();
        qDebug() << variable;

        QSqlQueryModel * modal=new QSqlQueryModel();
        modal->setQuery(query);
        ui->tableView->setModel(modal);
    }
}

void Login_DB::on_pushButtonGotoDR_clicked()
{
    DisplayRebate secondDialog;

    secondDialog.setModal(true);
    secondDialog.exec();
}

void Login_DB::on_pushButtonGotoEM_clicked()
{
    ExpiringMembers secondDialog;

    secondDialog.setModal(true);
    secondDialog.exec();
}

void Login_DB::on_pushButtonGotoAD_clicked()
{
    AddDelete secondDialog;

    secondDialog.setModal(true);
    secondDialog.exec();
}

void Login_DB::on_pushButtonGotoAD_2_clicked()
{
    AddDeleteItems secondDialog;

    secondDialog.setModal(true);
    secondDialog.exec();
}

void Login_DB::on_pushButtonGotoEM_2_clicked()
{
    CreatePurchases secondDialog;

    secondDialog.setModal(true);
    secondDialog.exec();
}

void Login_DB::on_pushButtonGotoDR_2_clicked()
{
    DisplayItemsSold secondDialog;

    secondDialog.setModal(true);
    secondDialog.exec();
}
