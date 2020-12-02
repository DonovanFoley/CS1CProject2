/********************************************************************************
** Form generated from reading UI file 'adddeleteitems.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDDELETEITEMS_H
#define UI_ADDDELETEITEMS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_AddDeleteItems
{
public:
    QPushButton *pushButton_Delete;
    QLineEdit *edit_Name;
    QRadioButton *radio_Stock;
    QPushButton *pushButton_Add;
    QLabel *label;
    QLineEdit *edit_Price;
    QLabel *label_5;
    QPushButton *pushButton_Edit;

    void setupUi(QDialog *AddDeleteItems)
    {
        if (AddDeleteItems->objectName().isEmpty())
            AddDeleteItems->setObjectName(QString::fromUtf8("AddDeleteItems"));
        AddDeleteItems->resize(400, 134);
        pushButton_Delete = new QPushButton(AddDeleteItems);
        pushButton_Delete->setObjectName(QString::fromUtf8("pushButton_Delete"));
        pushButton_Delete->setGeometry(QRect(300, 90, 75, 24));
        edit_Name = new QLineEdit(AddDeleteItems);
        edit_Name->setObjectName(QString::fromUtf8("edit_Name"));
        edit_Name->setEnabled(true);
        edit_Name->setGeometry(QRect(130, 30, 113, 22));
        radio_Stock = new QRadioButton(AddDeleteItems);
        radio_Stock->setObjectName(QString::fromUtf8("radio_Stock"));
        radio_Stock->setGeometry(QRect(20, 70, 161, 21));
        pushButton_Add = new QPushButton(AddDeleteItems);
        pushButton_Add->setObjectName(QString::fromUtf8("pushButton_Add"));
        pushButton_Add->setGeometry(QRect(300, 30, 75, 24));
        label = new QLabel(AddDeleteItems);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 30, 91, 16));
        edit_Price = new QLineEdit(AddDeleteItems);
        edit_Price->setObjectName(QString::fromUtf8("edit_Price"));
        edit_Price->setEnabled(true);
        edit_Price->setGeometry(QRect(130, 50, 113, 22));
        label_5 = new QLabel(AddDeleteItems);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(20, 50, 91, 16));
        pushButton_Edit = new QPushButton(AddDeleteItems);
        pushButton_Edit->setObjectName(QString::fromUtf8("pushButton_Edit"));
        pushButton_Edit->setGeometry(QRect(300, 60, 75, 24));

        retranslateUi(AddDeleteItems);

        QMetaObject::connectSlotsByName(AddDeleteItems);
    } // setupUi

    void retranslateUi(QDialog *AddDeleteItems)
    {
        AddDeleteItems->setWindowTitle(QCoreApplication::translate("AddDeleteItems", "Dialog", nullptr));
        pushButton_Delete->setText(QCoreApplication::translate("AddDeleteItems", "Delete", nullptr));
        radio_Stock->setText(QCoreApplication::translate("AddDeleteItems", "In Stock (Check if true)", nullptr));
        pushButton_Add->setText(QCoreApplication::translate("AddDeleteItems", "Add", nullptr));
        label->setText(QCoreApplication::translate("AddDeleteItems", "Name", nullptr));
        label_5->setText(QCoreApplication::translate("AddDeleteItems", "Price", nullptr));
        pushButton_Edit->setText(QCoreApplication::translate("AddDeleteItems", "Edit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddDeleteItems: public Ui_AddDeleteItems {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDDELETEITEMS_H
