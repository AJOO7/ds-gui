#include "admindisplay.h"
#include "ui_admindisplay.h"

adminDisplay::adminDisplay(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adminDisplay)
{
    ui->setupUi(this);
}

adminDisplay::~adminDisplay()
{
    delete ui;
}

void adminDisplay::on_back_clicked()
{
    this->close();

    // Show the MainWindow (i.e. the parent window)
    QWidget *parent = this->parentWidget();
    parent->show();
}

void adminDisplay::on_discount_clicked()
{
    dis=new adminDiscount(this);
    hide();
    dis->show();
}

void adminDisplay::on_pushButton_2_clicked()
{
    veg=new adminVeg(this);
    hide();
    veg->show();
}

void adminDisplay::on_nonVeg_clicked()
{
    non=new adminNonVeg(this);
    hide();
    non->show();
}

void adminDisplay::on_chinese_clicked()
{
    chin=new adminChinese(this);
    hide();
    chin->show();
}
