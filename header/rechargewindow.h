#ifndef RECHARGEWINDOW_H
#define RECHARGEWINDOW_H

#include <QWidget>

namespace Ui {
class rechargewindow;
}

class rechargewindow : public QWidget
{
    Q_OBJECT

public:
    explicit rechargewindow(QWidget *parent = 0);
    ~rechargewindow();

private slots:
    void on_charge_clicked();

private:
    Ui::rechargewindow *ui;
};

#endif // RECHARGEWINDOW_H
