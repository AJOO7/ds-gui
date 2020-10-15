#ifndef ADMINCHINESE_H
#define ADMINCHINESE_H

#include <QDialog>

namespace Ui {
class adminChinese;
}

class adminChinese : public QDialog
{
    Q_OBJECT

public:
    explicit adminChinese(QWidget *parent = nullptr);
    ~adminChinese();

private slots:
    void on_back_clicked();

    void on_add_clicked();

    void on_del_clicked();

private:
    Ui::adminChinese *ui;
};

#endif // ADMINCHINESE_H
