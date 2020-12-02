#include "login_db.h"
#include "displayitemssold.h"
#include "ui_displayitemssold.h"
#include <QMessageBox>

DisplayItemsSold::DisplayItemsSold(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DisplayItemsSold)
{
    ui->setupUi(this);
}

void DisplayItemsSold::TableWidgetDisplay()
{
    int index = 0;      //Input index
    int maxIndex = 0;   //used to determine table slots

    struct item
    {
        int quantity = 0;

        double revenue = 0;

        QString itemName;
    };

    int quantity = 0;
    item item;                          //array of item

    double cost = 0;                    //cost of an item

    QSqlQuery query;                    //acceses customers

    QString itemName;                   //item chosen

    //INPUT - Gets item name
    itemName = ui->lineEdit_Item->text();

    item.itemName = itemName;

    //INPUT - customer data
    query.prepare("select * from customerPurchases");
    if(!query.exec())
    {
        qDebug() << "ERROR " << query.lastError();
    }
    while(query.next())
    {
        QString variable = query.value(5).toString();   //temporary variable to get item name

        //Debugging
        qDebug() << "The Item is " << variable;
        qDebug() << "Selected Item is " << itemName;

        if(variable == itemName)
        {
          //Debugging
          //qDebug() << "I'm Here " << index;

          quantity = query.value(7).toInt();
          cost = query.value(6).toDouble();

          item.quantity = item.quantity + quantity;

          item.revenue = item.revenue + (cost*quantity);

          index++;
        }
    }


    //***BUILDS TABLE***//
    //ui->table
    //QTableWidget *table = new QTableWidget(this);
    ui->table->clear();
    ui->table->viewport()->update();
    ui->table->setRowCount(1);
    ui->table->setColumnCount(3);

    QStringList labels;     //used to set labels of table
    labels << "Item Name" << "Quantity" << "Revenue";
    ui->table->setHorizontalHeaderLabels(labels);

    //Debug


    //Sets table data
    for(int i = 0; i < ui->table->rowCount(); i++)
    {
        QTableWidgetItem *tItem;
        for(int i2 = 0; i2 < ui->table->columnCount(); i2++)
        {
            tItem = new QTableWidgetItem;

            if(i2 == 0)
            {
                tItem->setText(item.itemName);
            }
            if(i2 == 1)
            {
                tItem->setText(QString::number(item.quantity, 'f', 2));
            }
            if(i2 == 2)
            {
                tItem->setText(QString::number(item.revenue));
            }
            //if(i2 == 3)
           // {
                //item->setText(QString::number(execAR[i].getCost(), 'f', 2));
                //qDebug() << "I'm printing " << i;
           // }
            ui->table->setItem(i,i2,tItem);
        }
    }

}

DisplayItemsSold::~DisplayItemsSold()
{
    delete ui;
}

void DisplayItemsSold::on_pushButton_clicked()
{
    //Calls TableWidgetDisplay
    TableWidgetDisplay();
}
