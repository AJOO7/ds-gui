#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <QDialog>
#include"orderdisplaly.h"
namespace Ui {
class customer;
}

class customer : public QDialog
{
    Q_OBJECT

public:
    explicit customer(QWidget *parent = nullptr);
    ~customer();

private slots:
    void on_back_clicked();

    void on_newCustomer_clicked();

    void on_login_clicked();

private:
    Ui::customer *ui;
    orderDisplaly*order;
};

#endif // CUSTOMER_H
