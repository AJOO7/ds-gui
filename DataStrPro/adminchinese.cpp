#include "adminchinese.h"
#include "ui_adminchinese.h"
#include<QString>
#include <cstddef>
#include<QMessageBox>
#include<QFile>
#include<QTextStream>
class node
{
    QString food;
    int price;
    int no_of_order;
    node *next;
public:
    node(QString f,int p)
    {
        food=f;
        price=p;
        no_of_order=0;
        next=NULL;
    }
    friend class Menu;
};
class Menu
{
    node *head;
    node *tail;
public:
    Menu()
    {
        head=NULL;
        tail=NULL;
    }
    void insert_dish(QString f,int p)
    {
        node *n = new node(f,p);
        if(head==NULL)
        {
            head=tail=n;
            return;
        }
        tail->next=n;
        tail=n;
        return;
    }
    void fill_file()
    {   QFile filec("C:/Users/Alisha/Documents/DataStrPro/chinese.txt");
        filec.open(QIODevice::WriteOnly |QIODevice::Text);
        QTextStream out(&filec);
        filec.resize(0);
        if(head==NULL)
        {
            out<<"END";
            return;
        }
        node *temp=head;
        while(temp!=NULL)
        {
            out<<temp->food<<Qt::endl;
            out<<temp->price<<Qt::endl;
            temp=temp->next;
        }
        out<<"END";
        filec.close();
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
            node*curr=head;
            head=head->next;
            delete curr;
            return;
        }
        node*temp=head;
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
        node *t=temp->next;
        temp->next=t->next;
        delete t;
        return;
    }
};
Menu chi;
adminChinese::adminChinese(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adminChinese)
{
    ui->setupUi(this);
    QFile filec("C:/Users/Alisha/Documents/DataStrPro/chinese.txt");
    filec.open(QFile::ReadOnly |QFile::Text);
    QTextStream in(&filec);
    QString text=in.readLine();
    QString text2=in.readLine();
    while(text!="END"){
        chi.insert_dish(text,text2.toInt());
        text=in.readLine();
        text2=in.readLine();
    }
    filec.close();
}

adminChinese::~adminChinese()
{
    delete ui;
}

void adminChinese::on_back_clicked()
{
    this->close();

    // Show the MainWindow (i.e. the parent window)
    QWidget *parent = this->parentWidget();
    parent->show();
}

void adminChinese::on_add_clicked()
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
    chi.insert_dish(newName,newPrice);
    chi.fill_file();
}

void adminChinese::on_del_clicked()
{
    QString name=ui->delFood->text();
    chi.delete_dish(name);
    chi.fill_file();
}
