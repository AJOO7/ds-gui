#ifndef ADMINDISCOUNT_H
#define ADMINDISCOUNT_H
#include"orderprice.h"
#include <QDialog>

namespace Ui {
class adminDiscount;
}

class adminDiscount : public QDialog
{
    Q_OBJECT

public:
    explicit adminDiscount(QWidget *parent = nullptr);
    ~adminDiscount();

private slots:
    void on_back_clicked();

    void on_add_clicked();

private:
    Ui::adminDiscount *ui;
};

#endif // ADMINDISCOUNT_H
