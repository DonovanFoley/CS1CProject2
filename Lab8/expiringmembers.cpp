#include "login_db.h"
#include "expiringmembers.h"
#include "ui_expiringmembers.h"
#include <QMessageBox>

ExpiringMembers::ExpiringMembers(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ExpiringMembers)
{
    ui->setupUi(this);
    TableWidgetDisplay();
}

ExpiringMembers::~ExpiringMembers()
{
    delete ui;
}

void ExpiringMembers::TableWidgetDisplay()
{
    int index = 0;      //Input index
    int maxIndex = 0;   //used to determine table slots

    ExecutiveMember execAR[350];    //array of ExecutiveMember
    QSqlQuery query;                //acceses customers

    QString month;                  //month chosen

    //INPUT - Gets month
    month = ui->lineEdit_Month->text();

    //INPUT - customer data
    query.prepare("select * from customers");
    if(!query.exec())
    {
        qDebug() << "ERROR " << query.lastError();
    }
    while(query.next())
    {
        QString temp;                                   //temporary variable to get month
        QString variable = query.value(4).toString();   //temporary variable to get month
        temp = variable[0];

        temp = temp + variable[1];

        //Debugging
        //qDebug() << "The month is " << temp;
        //qDebug() << "Selected Month is " << month;

        if(temp == month)
        {
          //Debugging
          //qDebug() << "I'm Here " << index;

          execAR[index].setFirstName(query.value(0).toString());
          execAR[index].setLastName(query.value(1).toString());
          execAR[index].setID(query.value(2).toString());
          execAR[index].setCost(query.value(5).toString());
          index++;
        }
    }

    maxIndex = index;
    //CALC - sorts low->high
    for(int i = 0; i< maxIndex; i++)
    {
        for(int i2 = i + 1; i2 < maxIndex; i2++)
        {
            if(execAR[i].getID() > execAR[i2].getID())
            {
                ExecutiveMember temp;
                temp  = execAR[i];
                execAR[i] = execAR[i2];
                execAR[i2] = temp;
            }
        }
    }


    //***BUILDS TABLE***//
    //ui->table
    //QTableWidget *table = new QTableWidget(this);
    ui->table->clear();
    ui->table->viewport()->update();
    ui->table->setRowCount(maxIndex);
    ui->table->setColumnCount(4);

    QStringList labels;     //used to set labels of table
    labels << "First Name" << "Last Name" << "ID" << "Cost to Renew";
    ui->table->setHorizontalHeaderLabels(labels);

    //Sets table data
    for(int i = 0; i < ui->table->rowCount(); i++)
    {
        QTableWidgetItem *item;
        for(int i2 = 0; i2 < ui->table->columnCount(); i2++)
        {
            item = new QTableWidgetItem;

            if(i2 == 0)
            {
                item->setText(execAR[i].getFirstName());
            }
            if(i2 == 1)
            {
                item->setText(execAR[i].getLastName());
            }
            if(i2 == 2)
            {
                item->setText(QString::number(execAR[i].getID()));
            }
            if(i2 == 3)
            {
                item->setText(QString::number(execAR[i].getCost(), 'f', 2));
                //Debug
                //qDebug() << "I'm printing " << i;
            }
            ui->table->setItem(i,i2,item);
        }
    }

}

void ExpiringMembers::on_pushButton_clicked()
{
    //Calls TableWidgetDisplay
    TableWidgetDisplay();
}
