#ifndef LOGIN_DB_H
#define LOGIN_DB_H

#include <QMainWindow>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>
#include <QSqlTableModel>
#include <QDebug>
#include <QDialog>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QMainWindow>
#include "ExecutiveClass.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Login_DB; }
QT_END_NAMESPACE

class Login_DB : public QMainWindow
{
    Q_OBJECT

public:
    Login_DB(QWidget *parent = nullptr);
    ~Login_DB();

private slots:

    void on_pushButtonGotoAD_clicked();

    void on_pushButton_loadTable_clicked();

    void on_pushButtonGotoDR_clicked();

    void on_pushButtonGotoEM_clicked();

    void on_pushButtonGotoAD_2_clicked();

    void on_pushButtonGotoEM_2_clicked();

    void on_pushButtonGotoDR_2_clicked();

private:
    Ui::Login_DB *ui;
};
#endif // LOGIN_DB_H
