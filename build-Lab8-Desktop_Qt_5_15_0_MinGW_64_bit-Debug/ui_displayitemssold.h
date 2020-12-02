/********************************************************************************
** Form generated from reading UI file 'displayitemssold.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DISPLAYITEMSSOLD_H
#define UI_DISPLAYITEMSSOLD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_DisplayItemsSold
{
public:
    QTableWidget *table;
    QLabel *label;
    QPushButton *pushButton;
    QLineEdit *lineEdit_Item;

    void setupUi(QDialog *DisplayItemsSold)
    {
        if (DisplayItemsSold->objectName().isEmpty())
            DisplayItemsSold->setObjectName(QString::fromUtf8("DisplayItemsSold"));
        DisplayItemsSold->resize(400, 500);
        table = new QTableWidget(DisplayItemsSold);
        table->setObjectName(QString::fromUtf8("table"));
        table->setGeometry(QRect(-10, 0, 401, 441));
        label = new QLabel(DisplayItemsSold);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 460, 91, 16));
        pushButton = new QPushButton(DisplayItemsSold);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(230, 450, 91, 41));
        lineEdit_Item = new QLineEdit(DisplayItemsSold);
        lineEdit_Item->setObjectName(QString::fromUtf8("lineEdit_Item"));
        lineEdit_Item->setGeometry(QRect(100, 460, 113, 20));

        retranslateUi(DisplayItemsSold);

        QMetaObject::connectSlotsByName(DisplayItemsSold);
    } // setupUi

    void retranslateUi(QDialog *DisplayItemsSold)
    {
        DisplayItemsSold->setWindowTitle(QCoreApplication::translate("DisplayItemsSold", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("DisplayItemsSold", "Enter the Month", nullptr));
        pushButton->setText(QCoreApplication::translate("DisplayItemsSold", "Search", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DisplayItemsSold: public Ui_DisplayItemsSold {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DISPLAYITEMSSOLD_H
