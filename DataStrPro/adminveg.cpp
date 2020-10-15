#include "adminveg.h"
#include "ui_adminveg.h"
#include<QString>
#include <cstddef>
#include<QMessageBox>
#include<QFile>
#include<QTextStream>
class node_veg
{
    QString food;
    int price;
    int no_of_order;
    node_veg *next;
public:
    node_veg(QString f,int p)
    {
        food=f;
        price=p;
        no_of_order=0;
        next=NULL;
    }
    friend class Menu_veg;
};
class Menu_veg
{
    node_veg *head;
    node_veg *tail;
public:
    Menu_veg()
    {
        head=NULL;
        tail=NULL;
    }
    void insert_dish_veg(QString f,int p)
    {
        node_veg *n = new node_veg(f,p);
        if(head==NULL)
        {
            head=tail=n;
            return;
        }
        tail->next=n;
        tail=n;
        return;
    }
    void fill_file_veg()
    {   QFile file1("C:/Users/Alisha/Documents/DataStrPro/veg.txt");
        file1.open(QIODevice::WriteOnly |QIODevice::Text);
        QTextStream out(&file1);
        file1.resize(0);
        if(head==NULL)
        {
            out<<"END";
            return;
        }
        node_veg *temp=head;
        while(temp!=NULL)
        {
            out<<temp->food<<Qt::endl;
            out<<temp->price<<Qt::endl;
            temp=temp->next;
        }
        out<<"END";
        file1.close();
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
            node_veg*curr=head;
            head=head->next;
            delete curr;
            return;
        }
        bool found=false;
        node_veg*temp=head;
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
        node_veg *t=temp->next;
        temp->next=t->next;
        delete t;
        return;
    }
};
Menu_veg veg;
adminVeg::adminVeg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adminVeg)
{
    ui->setupUi(this);
    QFile file("C:/Users/Alisha/Documents/DataStrPro/veg.txt");
    file.open(QFile::ReadOnly |QFile::Text);
    QTextStream in(&file);
    QString text=in.readLine();
    QString text2=in.readLine();
    while(text!="END"){
        veg.insert_dish_veg(text,text2.toInt());
        text=in.readLine();
        text2=in.readLine();
    }
    file.close();
//    ui->vegFood->setText(text);
}

adminVeg::~adminVeg()
{
    delete ui;
}

void adminVeg::on_back_clicked()
{
    this->close();

    // Show the MainWindow (i.e. the parent window)
    QWidget *parent = this->parentWidget();
    parent->show();
}
class function
{
public:
    function();

};


void adminVeg::on_add_clicked()
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
    veg.insert_dish_veg(newName,newPrice);
    veg.fill_file_veg();

}

void adminVeg::on_del_clicked()
{
       QString name=ui->delFood->text();
       veg.delete_dish(name);
       veg.fill_file_veg();
}
