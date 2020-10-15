#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"logindialog.h"
#include"customer.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_admin_clicked();

    void on_placeOrder_clicked();

private:
    Ui::MainWindow *ui;
    loginDialog* login;
    customer*cus;
};
#endif // MAINWINDOW_H
