#include "customer.h"
#include "ui_customer.h"
#include<QString>
#include <cstddef>
#include<QMessageBox>
#include<QFile>
#include<QTextStream>
class Node
{
    int id;
    int c;
    int visits;
    Node *Next;
public:
    Node()
    {
        QFile filecus("C:/Users/Alisha/Documents/DataStrPro/lastid.txt");
        filecus.open(QFile::ReadOnly |QFile::Text);
        QTextStream in(&filecus);
        QString text=in.readLine();
        filecus.close();
        int temp=text.toInt();
        temp+=1;
        QFile filecu("C:/Users/Alisha/Documents/DataStrPro/lastid.txt");
        filecu.open(QIODevice::WriteOnly |QIODevice::Text);
        QTextStream out(&filecu);
        QString newText=QString::number(temp);
        filecu.resize(0);
        out<<newText<<Qt::endl;
        filecu.close();
        c=newText.toInt();
        id=1000 + c;
        visits=1;
        Next=NULL;
    }
    friend class Customer;
};
class Customer
{
    Node *start;
    Node *End;
public:
    Customer()
    {
        start=NULL;
        End=NULL;
    }
    void cus_insert_old(Node *t,int id,int v)
    {
        if(start==NULL)
        {
            start=End=t;
            return ;
        }
        End->Next=t;
        t->visits=v;
        t->id=id;
        End=t;
        return ;
    }
    void cus_insert_new(Node*t){
        if(start==NULL)
        {
            start=End=t;
            return ;
        }
        End->Next=t;
        End=t;
        return ;
    }
    void fill_file()
    {   QFile filef("C:/Users/Alisha/Documents/DataStrPro/customer.txt");
        filef.open(QIODevice::WriteOnly |QIODevice::Text);
        QTextStream out(&filef);
        filef.resize(0);
        if(start==NULL)
        {
            out<<"END";
            return;
        }
        Node *temp=start;
        while(temp!=NULL)
        {
            out<<temp->id<<Qt::endl;
            out<<temp->visits<<Qt::endl;
            temp=temp->Next;
        }
        out<<"END";
        filef.close();
        return;
    }
    int  inc_visit(int n)
    {
        Node*temp=start;
        while(temp!=NULL && temp->id!=n)
        {
            temp=temp->Next;
        }
        if(temp==NULL)
        {
//            QMessageBox msgBox;
//           msgBox.setText("id is not present!");
//            msgBox.setStandardButtons( QMessageBox::Ok);
//            msgBox.setDefaultButton(QMessageBox::Ok);
//             msgBox.exec();
            return -1;
        }
        temp->visits=temp->visits+1;
        return 0;
    }
};
Customer cus;
customer::customer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::customer)
{
    ui->setupUi(this);
    QFile fileq("C:/Users/Alisha/Documents/DataStrPro/customer.txt");
    fileq.open(QFile::ReadOnly |QFile::Text);
    QTextStream in(&fileq);
    QString text;
    QString text2;
    while(text!="END"){
        Node *t = new Node();
        text=in.readLine();
        text2=in.readLine();
        cus.cus_insert_old(t,text.toInt(),text2.toInt());

    }
    fileq.close();
}

customer::~customer()
{
    delete ui;
}

void customer::on_back_clicked()
{
    this->close();
    QWidget *parent = this->parentWidget();
    parent->show();

}

void customer::on_newCustomer_clicked()
{
    Node *t = new Node();
    cus.cus_insert_new(t);
    cus.fill_file();
    order=new orderDisplaly(this);
    hide();
    order->show();
}

void customer::on_login_clicked()
{
    int check=ui->customerId->text().toInt();
    int result=cus.inc_visit(check);
    if(result==-1){
        QMessageBox::information(this,"Warning","id is not present!");
    }else{
    cus.fill_file();
    order=new orderDisplaly(this);
    hide();
    order->show();
    }

}
