#include "mainwindow.h"
#include "totalpurchases.h"
#include "productdisplay.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    totalPurchases go;
    go.setModal(true);
    go.exec();
}

void MainWindow::on_pushButton_2_clicked()
{
    ProductDisplay go;
    go.setModal(true);
    go.exec();
}
