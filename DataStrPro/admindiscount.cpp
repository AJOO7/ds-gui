#include "admindiscount.h"
#include "ui_admindiscount.h"
#include<QString>
#include <cstddef>
#include<QMessageBox>
#include<QFile>
#include<QTextStream>
adminDiscount::adminDiscount(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adminDiscount)
{
    ui->setupUi(this);
}

adminDiscount::~adminDiscount()
{
    delete ui;
}

void adminDiscount::on_back_clicked()
{
    this->close();

    // Show the MainWindow (i.e. the parent window)
    QWidget *parent = this->parentWidget();
    parent->show();
}

void adminDiscount::on_add_clicked()
{
            QFile filed("C:/Users/Alisha/Documents/DataStrPro/discount.txt");
            filed.open(QIODevice::WriteOnly |QIODevice::Text);
            QTextStream out(&filed);
            filed.resize(0);
            out<<ui->discount->text()<<Qt::endl;
            out<<"END";
            filed.close();

}
