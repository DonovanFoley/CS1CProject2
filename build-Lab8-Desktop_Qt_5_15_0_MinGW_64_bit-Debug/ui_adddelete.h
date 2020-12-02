/********************************************************************************
** Form generated from reading UI file 'adddelete.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDDELETE_H
#define UI_ADDDELETE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_AddDelete
{
public:
    QLineEdit *edit_FirstName;
    QLineEdit *edit_Type;
    QLineEdit *edit_Number;
    QLineEdit *edit_ExpDate;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_4;
    QPushButton *pushButton_Add;
    QPushButton *pushButton_Delete;
    QLineEdit *edit_LastName;
    QLabel *label_5;
    QRadioButton *radio_Executive;

    void setupUi(QDialog *AddDelete)
    {
        if (AddDelete->objectName().isEmpty())
            AddDelete->setObjectName(QString::fromUtf8("AddDelete"));
        AddDelete->resize(395, 177);
        edit_FirstName = new QLineEdit(AddDelete);
        edit_FirstName->setObjectName(QString::fromUtf8("edit_FirstName"));
        edit_FirstName->setEnabled(true);
        edit_FirstName->setGeometry(QRect(130, 40, 113, 22));
        edit_Type = new QLineEdit(AddDelete);
        edit_Type->setObjectName(QString::fromUtf8("edit_Type"));
        edit_Type->setGeometry(QRect(140, 80, 71, 20));
        edit_Number = new QLineEdit(AddDelete);
        edit_Number->setObjectName(QString::fromUtf8("edit_Number"));
        edit_Number->setGeometry(QRect(130, 80, 113, 22));
        edit_ExpDate = new QLineEdit(AddDelete);
        edit_ExpDate->setObjectName(QString::fromUtf8("edit_ExpDate"));
        edit_ExpDate->setGeometry(QRect(130, 100, 113, 22));
        label = new QLabel(AddDelete);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 40, 91, 16));
        label_2 = new QLabel(AddDelete);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 80, 111, 16));
        label_4 = new QLabel(AddDelete);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 100, 111, 16));
        pushButton_Add = new QPushButton(AddDelete);
        pushButton_Add->setObjectName(QString::fromUtf8("pushButton_Add"));
        pushButton_Add->setGeometry(QRect(300, 40, 75, 24));
        pushButton_Delete = new QPushButton(AddDelete);
        pushButton_Delete->setObjectName(QString::fromUtf8("pushButton_Delete"));
        pushButton_Delete->setGeometry(QRect(300, 70, 75, 24));
        edit_LastName = new QLineEdit(AddDelete);
        edit_LastName->setObjectName(QString::fromUtf8("edit_LastName"));
        edit_LastName->setEnabled(true);
        edit_LastName->setGeometry(QRect(130, 60, 113, 22));
        label_5 = new QLabel(AddDelete);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(20, 60, 91, 16));
        radio_Executive = new QRadioButton(AddDelete);
        radio_Executive->setObjectName(QString::fromUtf8("radio_Executive"));
        radio_Executive->setGeometry(QRect(20, 120, 101, 21));

        retranslateUi(AddDelete);

        QMetaObject::connectSlotsByName(AddDelete);
    } // setupUi

    void retranslateUi(QDialog *AddDelete)
    {
        AddDelete->setWindowTitle(QCoreApplication::translate("AddDelete", "Add/Delete Members", nullptr));
        label->setText(QCoreApplication::translate("AddDelete", "First Name", nullptr));
        label_2->setText(QCoreApplication::translate("AddDelete", "Member Number", nullptr));
        label_4->setText(QCoreApplication::translate("AddDelete", "Expiration Date", nullptr));
        pushButton_Add->setText(QCoreApplication::translate("AddDelete", "Add", nullptr));
        pushButton_Delete->setText(QCoreApplication::translate("AddDelete", "Delete", nullptr));
        label_5->setText(QCoreApplication::translate("AddDelete", "Last Name", nullptr));
        radio_Executive->setText(QCoreApplication::translate("AddDelete", "Executive", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddDelete: public Ui_AddDelete {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDDELETE_H
