#ifndef ADMINVEG_H
#define ADMINVEG_H

#include <QDialog>
namespace Ui {
class adminVeg;
}

class adminVeg : public QDialog
{
    Q_OBJECT

public:
    explicit adminVeg(QWidget *parent = nullptr);
    ~adminVeg();

private slots:
    void on_back_clicked();

    void on_add_clicked();

    void on_del_clicked();

private:
    Ui::adminVeg *ui;
};

#endif // ADMINVEG_H
