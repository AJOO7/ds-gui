#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include"admindisplay.h"
namespace Ui {
class loginDialog;
}

class loginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit loginDialog(QWidget *parent = nullptr);
    ~loginDialog();

private slots:
    void on_back_clicked();

    void on_submit_clicked();

private:
    Ui::loginDialog *ui;
    adminDisplay* admin;
};

#endif // LOGINDIALOG_H
