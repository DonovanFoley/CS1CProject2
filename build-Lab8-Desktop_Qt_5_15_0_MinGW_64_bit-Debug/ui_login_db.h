/********************************************************************************
** Form generated from reading UI file 'login_db.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_DB_H
#define UI_LOGIN_DB_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Login_DB
{
public:
    QWidget *centralwidget;
    QTableView *tableView;
    QPushButton *pushButton_loadTable;
    QPushButton *pushButtonGotoAD;
    QPushButton *pushButtonGotoDR;
    QPushButton *pushButtonGotoEM;
    QPushButton *pushButtonGotoDR_2;
    QPushButton *pushButtonGotoAD_2;
    QPushButton *pushButtonGotoEM_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Login_DB)
    {
        if (Login_DB->objectName().isEmpty())
            Login_DB->setObjectName(QString::fromUtf8("Login_DB"));
        Login_DB->resize(800, 600);
        centralwidget = new QWidget(Login_DB);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tableView = new QTableView(centralwidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(50, 20, 361, 231));
        pushButton_loadTable = new QPushButton(centralwidget);
        pushButton_loadTable->setObjectName(QString::fromUtf8("pushButton_loadTable"));
        pushButton_loadTable->setGeometry(QRect(170, 310, 161, 51));
        pushButtonGotoAD = new QPushButton(centralwidget);
        pushButtonGotoAD->setObjectName(QString::fromUtf8("pushButtonGotoAD"));
        pushButtonGotoAD->setGeometry(QRect(360, 490, 121, 24));
        pushButtonGotoDR = new QPushButton(centralwidget);
        pushButtonGotoDR->setObjectName(QString::fromUtf8("pushButtonGotoDR"));
        pushButtonGotoDR->setGeometry(QRect(30, 490, 151, 24));
        pushButtonGotoEM = new QPushButton(centralwidget);
        pushButtonGotoEM->setObjectName(QString::fromUtf8("pushButtonGotoEM"));
        pushButtonGotoEM->setGeometry(QRect(190, 490, 151, 24));
        pushButtonGotoDR_2 = new QPushButton(centralwidget);
        pushButtonGotoDR_2->setObjectName(QString::fromUtf8("pushButtonGotoDR_2"));
        pushButtonGotoDR_2->setGeometry(QRect(360, 520, 151, 24));
        pushButtonGotoAD_2 = new QPushButton(centralwidget);
        pushButtonGotoAD_2->setObjectName(QString::fromUtf8("pushButtonGotoAD_2"));
        pushButtonGotoAD_2->setGeometry(QRect(190, 520, 151, 24));
        pushButtonGotoEM_2 = new QPushButton(centralwidget);
        pushButtonGotoEM_2->setObjectName(QString::fromUtf8("pushButtonGotoEM_2"));
        pushButtonGotoEM_2->setGeometry(QRect(30, 520, 151, 24));
        Login_DB->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Login_DB);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        Login_DB->setMenuBar(menubar);
        statusbar = new QStatusBar(Login_DB);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Login_DB->setStatusBar(statusbar);

        retranslateUi(Login_DB);

        QMetaObject::connectSlotsByName(Login_DB);
    } // setupUi

    void retranslateUi(QMainWindow *Login_DB)
    {
        Login_DB->setWindowTitle(QCoreApplication::translate("Login_DB", "Login_DB", nullptr));
        pushButton_loadTable->setText(QCoreApplication::translate("Login_DB", "Reload Table", nullptr));
        pushButtonGotoAD->setText(QCoreApplication::translate("Login_DB", "GoTo Add/Delete", nullptr));
        pushButtonGotoDR->setText(QCoreApplication::translate("Login_DB", "GoTo Display Rebate", nullptr));
        pushButtonGotoEM->setText(QCoreApplication::translate("Login_DB", "GoTo Expiring Members", nullptr));
        pushButtonGotoDR_2->setText(QCoreApplication::translate("Login_DB", "GoTo Display Item Sold", nullptr));
        pushButtonGotoAD_2->setText(QCoreApplication::translate("Login_DB", "GoTo Add/Delete Items", nullptr));
        pushButtonGotoEM_2->setText(QCoreApplication::translate("Login_DB", "GoTo Create Purchases", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Login_DB: public Ui_Login_DB {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_DB_H
