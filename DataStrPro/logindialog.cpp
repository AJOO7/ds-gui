#include "logindialog.h"
#include "ui_logindialog.h"
#include<QMessageBox>
loginDialog::loginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::loginDialog)
{
    ui->setupUi(this);
}

loginDialog::~loginDialog()
{
    delete ui;
}

void loginDialog::on_back_clicked()
{
    this->close();

    // Show the MainWindow (i.e. the parent window)
    QWidget *parent = this->parentWidget();
    parent->show();
}

void loginDialog::on_submit_clicked()
{
    QString name="Ajay@123";
    QString pass="Ajay@123";
    if(ui->username->text()==name && ui->password->text()==pass){
        admin=new adminDisplay(this);
        hide();
        admin->show();
    }
    else {
       QMessageBox::information(this,"Warning","Wrong name or wrong password");
    }

}
