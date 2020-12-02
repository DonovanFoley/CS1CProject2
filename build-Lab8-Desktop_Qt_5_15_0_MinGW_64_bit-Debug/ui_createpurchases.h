/********************************************************************************
** Form generated from reading UI file 'createpurchases.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEPURCHASES_H
#define UI_CREATEPURCHASES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_CreatePurchases
{
public:
    QPushButton *pushButton_Delete;
    QLineEdit *edit_Name;
    QLabel *label_2;
    QLineEdit *edit_Number;
    QPushButton *pushButton_Add;
    QLabel *label;
    QLineEdit *edit_Quantity;
    QLabel *label_5;
    QLineEdit *edit_Date;
    QLabel *label_3;

    void setupUi(QDialog *CreatePurchases)
    {
        if (CreatePurchases->objectName().isEmpty())
            CreatePurchases->setObjectName(QString::fromUtf8("CreatePurchases"));
        CreatePurchases->resize(400, 178);
        pushButton_Delete = new QPushButton(CreatePurchases);
        pushButton_Delete->setObjectName(QString::fromUtf8("pushButton_Delete"));
        pushButton_Delete->setGeometry(QRect(300, 50, 75, 24));
        edit_Name = new QLineEdit(CreatePurchases);
        edit_Name->setObjectName(QString::fromUtf8("edit_Name"));
        edit_Name->setEnabled(true);
        edit_Name->setGeometry(QRect(130, 20, 113, 22));
        label_2 = new QLabel(CreatePurchases);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 60, 111, 16));
        edit_Number = new QLineEdit(CreatePurchases);
        edit_Number->setObjectName(QString::fromUtf8("edit_Number"));
        edit_Number->setGeometry(QRect(130, 60, 113, 22));
        pushButton_Add = new QPushButton(CreatePurchases);
        pushButton_Add->setObjectName(QString::fromUtf8("pushButton_Add"));
        pushButton_Add->setGeometry(QRect(300, 20, 75, 24));
        label = new QLabel(CreatePurchases);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 20, 91, 16));
        edit_Quantity = new QLineEdit(CreatePurchases);
        edit_Quantity->setObjectName(QString::fromUtf8("edit_Quantity"));
        edit_Quantity->setEnabled(true);
        edit_Quantity->setGeometry(QRect(130, 40, 113, 22));
        label_5 = new QLabel(CreatePurchases);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(20, 40, 91, 16));
        edit_Date = new QLineEdit(CreatePurchases);
        edit_Date->setObjectName(QString::fromUtf8("edit_Date"));
        edit_Date->setGeometry(QRect(130, 80, 113, 22));
        label_3 = new QLabel(CreatePurchases);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 80, 111, 16));

        retranslateUi(CreatePurchases);

        QMetaObject::connectSlotsByName(CreatePurchases);
    } // setupUi

    void retranslateUi(QDialog *CreatePurchases)
    {
        CreatePurchases->setWindowTitle(QCoreApplication::translate("CreatePurchases", "Dialog", nullptr));
        pushButton_Delete->setText(QCoreApplication::translate("CreatePurchases", "Delete", nullptr));
        label_2->setText(QCoreApplication::translate("CreatePurchases", "Member Number", nullptr));
        pushButton_Add->setText(QCoreApplication::translate("CreatePurchases", "Add", nullptr));
        label->setText(QCoreApplication::translate("CreatePurchases", "Item Name", nullptr));
        label_5->setText(QCoreApplication::translate("CreatePurchases", "Quantity", nullptr));
        label_3->setText(QCoreApplication::translate("CreatePurchases", "Date of Purchase", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CreatePurchases: public Ui_CreatePurchases {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEPURCHASES_H
