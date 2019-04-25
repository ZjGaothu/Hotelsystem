#ifndef MYORDER_H
#define MYORDER_H

#include <QWidget>

namespace Ui {
class myorder;
}

class myorder : public QWidget
{
    Q_OBJECT

public:
    explicit myorder(QWidget *parent = 0);
    ~myorder();

private slots:
    void on_paybutton_clicked();

    void on_refund_clicked();

    void on_scorebutton_clicked();

    void on_changepass_clicked();

private:
    Ui::myorder *ui;
};

#endif // MYORDER_H
