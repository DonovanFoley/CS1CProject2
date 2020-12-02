#include "login_db.h"
#include "displayrebate.h"
#include "ui_displayrebate.h"

DisplayRebate::DisplayRebate(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DisplayRebate)
{
    ui->setupUi(this);

    TableWidgetDisplay();
}

DisplayRebate::~DisplayRebate()
{
    delete ui;
}

void DisplayRebate::TableWidgetDisplay()
{
    int index = 0;       //index of input
    int maxIndex = 0;    //used to determine table slots

    double rebate = 0;   //rebate of user
    double itemCost = 0; //cost of bought items

    ExecutiveMember execAR[350];    //array of ExecutiveMember
    QSqlQuery query;                //query 1, acceses customers
    QSqlQuery rebateQuery;          //query 2, acceses customerPurchases

    //INPUT - first query (all data exect rebate)
    query.prepare("select * from customers");
    if(!query.exec())
    {
        qDebug() << "ERROR " << query.lastError();
    }
    while(query.next())
    {
        QString variable = query.value(3).toString();

        if(variable == "Executive")
        {
          execAR[index].setFirstName(query.value(0).toString());
          execAR[index].setLastName(query.value(1).toString());
          execAR[index].setID(query.value(2).toString());
          //execAR[index].setRebate(?);
          index++;
        }
    }

    //INPUT - second query (gets productPrice and ProductQuantity and calculates rebate)
    rebateQuery.prepare("select * from customerPurchases");
    if(!rebateQuery.exec())
    {
        qDebug() << "ERROR " << rebateQuery.lastError();
    }

    //INPUT - Gets rebate
    maxIndex = index;
    index = 0;
    while(index != maxIndex)
    {
        rebateQuery.first();

        //CALC - rebate for specific person
        while(rebateQuery.next())
        {
            int variable = rebateQuery.value(3).toInt();     //gets ID

            //Debugging
            //qDebug() << "This is the price" << rebateQuery.value(6).toString();
            //qDebug() << "This is the purchase ID " << variable;
            //qDebug() << "This is the ID " << execAR[index].getID();

            if(variable == execAR[index].getID())      //if ID == ID
            {
              itemCost = rebateQuery.value(6).toDouble() * rebateQuery.value(7).toDouble();

              rebate = rebate + itemCost;

              //Debugging
              //qDebug() << "This is the rebate" << rebate;

            }
        }
        rebate = rebate * 0.02;
        execAR[index].setRebate(rebate);

        //Debugging
        //qDebug() << execAR[index].getID();
        //qDebug() << execAR[index].getRebate();

        rebate = 0;
        index++;
    }

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
    QTableWidget *table = new QTableWidget(this);
    table->setRowCount(maxIndex);
    table->setColumnCount(4);

    QStringList labels;
    labels << "First Name" << "Last Name" << "ID" << "Rebate";
    table->setHorizontalHeaderLabels(labels);

    //Formatting
    table->setMaximumWidth(400);
    table->setMinimumWidth(400);
    table->setMaximumHeight(400);
    table->setMinimumHeight(400);

    for(int i = 0; i < table->rowCount(); i++)
    {
        QTableWidgetItem *item;
        for(int i2 = 0; i2 < table->columnCount(); i2++)
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
                item->setText(QString::number(execAR[i].getRebate()));
            }

            table->setItem(i,i2,item);
        }
    }
}
