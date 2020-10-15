#ifndef ADMINNONVEG_H
#define ADMINNONVEG_H

#include <QDialog>

namespace Ui {
class adminNonVeg;
}

class adminNonVeg : public QDialog
{
    Q_OBJECT

public:
    explicit adminNonVeg(QWidget *parent = nullptr);
    ~adminNonVeg();

private slots:
    void on_back_clicked();

    void on_add_clicked();

    void on_del_clicked();

private:
    Ui::adminNonVeg *ui;
};

#endif // ADMINNONVEG_H
