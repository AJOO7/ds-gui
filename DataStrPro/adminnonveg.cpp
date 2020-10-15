#include "adminnonveg.h"
#include "ui_adminnonveg.h"
#include<QString>
#include <cstddef>
#include<QMessageBox>
#include<QFile>
#include<QTextStream>
class node_non
{
    QString food;
    int price;
    int no_of_order;
    node_non *next;
public:
    node_non(QString f,int p)
    {
        food=f;
        price=p;
        no_of_order=0;
        next=NULL;
    }
    friend class Menu_non;
};
class Menu_non
{
    node_non *head;
    node_non *tail;
public:
    Menu_non()
    {
        head=NULL;
        tail=NULL;
    }
    void insert_dish_non(QString f,int p)
    {
        node_non *n = new node_non(f,p);
        if(head==NULL)
        {
            head=tail=n;
            return;
        }
        tail->next=n;
        tail=n;
        return;
    }
    void fill_file_non()
    {   QFile filen("C:/Users/Alisha/Documents/DataStrPro/nonVeg.txt");
        filen.open(QIODevice::WriteOnly |QIODevice::Text);

        QTextStream out(&filen);
        filen.resize(0);
        if(head==NULL)
        {
            out<<"END";
            return;
        }
        node_non *temp=head;
        while(temp!=NULL)
        {
            out<<temp->food<<Qt::endl;
            out<<temp->price<<Qt::endl;
            temp=temp->next;
        }
        out<<"END";
        filen.close();
        return;
    }
    void delete_dish(QString f)
    {
        if(head==NULL)
        {
            QMessageBox msgBox;
           msgBox.setText("Nothing present to be deleted!");
            msgBox.setStandardButtons( QMessageBox::Ok);
            msgBox.setDefaultButton(QMessageBox::Ok);
             msgBox.exec();
            return;
        }
        if(head->food==f&&head->next==NULL){
            delete head;
            head=NULL;
            return;
        }
        if(head->food==f&&head->next!=NULL){
            node_non*curr=head;
            head=head->next;
            delete curr;
            return;
        }
        node_non*temp=head;
        bool found=false;
        while(temp->next!=NULL)
        {
            if(temp->next->food==f){
                found=true;
                break;
            }
            temp=temp->next;
        }
        if(found==false)
        {
            QMessageBox msgBox;
            msgBox.setText("Dish not Found in the menu!");
            msgBox.setStandardButtons( QMessageBox::Ok);
            msgBox.setDefaultButton(QMessageBox::Ok);
             msgBox.exec();
            return;
        }
        node_non *t=temp->next;
        temp->next=t->next;
        delete t;
        return;
    }
};
Menu_non nonVeg;
adminNonVeg::adminNonVeg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adminNonVeg)
{
    ui->setupUi(this);
    QFile filen("C:/Users/Alisha/Documents/DataStrPro/nonVeg.txt");
    filen.open(QFile::ReadOnly |QFile::Text);
    QTextStream in(&filen);
    QString text=in.readLine();
    QString text2=in.readLine();
    while(text!="END"){
        nonVeg.insert_dish_non(text,text2.toInt());
        text=in.readLine();
        text2=in.readLine();
    }
    filen.close();
}

adminNonVeg::~adminNonVeg()
{
    delete ui;
}

void adminNonVeg::on_back_clicked()
{
    this->close();
    QWidget *parent = this->parentWidget();
    parent->show();
}

void adminNonVeg::on_add_clicked()
{
    QString newName=ui->foodName->text();
    if(newName==NULL){
        QMessageBox::information(this,"Warning","Empty username!");
        return;
    }
    int newPrice=ui->foodPrice->text().toInt();
    if(newPrice==NULL){
        QMessageBox::information(this,"Warning","Empty price!");
        return;
    }
    nonVeg.insert_dish_non(newName,newPrice);
    nonVeg.fill_file_non();
}

void adminNonVeg::on_del_clicked()
{
    QString name=ui->delFood->text();
    nonVeg.delete_dish(name);
    nonVeg.fill_file_non();
}
