#ifndef ADMINDISPLAY_H
#define ADMINDISPLAY_H

#include <QDialog>
#include"admindiscount.h"
#include"adminchinese.h"
#include"adminnonveg.h"
#include"adminveg.h"
namespace Ui {
class adminDisplay;
}

class adminDisplay : public QDialog
{
    Q_OBJECT

public:
    explicit adminDisplay(QWidget *parent = nullptr);
    ~adminDisplay();

private slots:
    void on_back_clicked();

    void on_discount_clicked();

    void on_pushButton_2_clicked();

    void on_nonVeg_clicked();

    void on_chinese_clicked();

private:
    Ui::adminDisplay *ui;
    adminDiscount*dis;
    adminChinese*chin;
    adminNonVeg*non;
    adminVeg*veg;
};

#endif // ADMINDISPLAY_H
