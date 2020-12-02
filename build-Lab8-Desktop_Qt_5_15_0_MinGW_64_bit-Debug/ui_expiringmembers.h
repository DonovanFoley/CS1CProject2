/********************************************************************************
** Form generated from reading UI file 'expiringmembers.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXPIRINGMEMBERS_H
#define UI_EXPIRINGMEMBERS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_ExpiringMembers
{
public:
    QPushButton *pushButton;
    QLineEdit *lineEdit_Month;
    QLabel *label;
    QTableWidget *table;

    void setupUi(QDialog *ExpiringMembers)
    {
        if (ExpiringMembers->objectName().isEmpty())
            ExpiringMembers->setObjectName(QString::fromUtf8("ExpiringMembers"));
        ExpiringMembers->resize(400, 500);
        pushButton = new QPushButton(ExpiringMembers);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(240, 450, 91, 41));
        lineEdit_Month = new QLineEdit(ExpiringMembers);
        lineEdit_Month->setObjectName(QString::fromUtf8("lineEdit_Month"));
        lineEdit_Month->setGeometry(QRect(110, 460, 113, 20));
        label = new QLabel(ExpiringMembers);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 460, 91, 16));
        table = new QTableWidget(ExpiringMembers);
        table->setObjectName(QString::fromUtf8("table"));
        table->setGeometry(QRect(0, 0, 401, 441));

        retranslateUi(ExpiringMembers);

        QMetaObject::connectSlotsByName(ExpiringMembers);
    } // setupUi

    void retranslateUi(QDialog *ExpiringMembers)
    {
        ExpiringMembers->setWindowTitle(QCoreApplication::translate("ExpiringMembers", "Expiring Members", nullptr));
        pushButton->setText(QCoreApplication::translate("ExpiringMembers", "Search", nullptr));
        label->setText(QCoreApplication::translate("ExpiringMembers", "Enter the Month", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ExpiringMembers: public Ui_ExpiringMembers {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXPIRINGMEMBERS_H
