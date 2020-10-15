#include "mainwindow.h"
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


void MainWindow::on_admin_clicked()
{
    login=new loginDialog(this);
    hide();
    login->show();
}

void MainWindow::on_placeOrder_clicked()
{
    cus= new customer(this);
    hide();
    cus->show();
}
