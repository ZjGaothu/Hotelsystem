#ifndef USRWINDOW_H
#define USRWINDOW_H

#include <QWidget>

namespace Ui {
class usrwindow;
}

class usrwindow : public QWidget
{
    Q_OBJECT

public:
    explicit usrwindow(QWidget *parent = 0);
    ~usrwindow();

private slots:
    void on_recharge_clicked();

    void on_searchbutton_clicked();

    void on_viewbutton_clicked();

    void on_myorder_clicked();

    void on_payback_clicked();

    void on_message_clicked();

    void on_pushButton_clicked();

private:
    Ui::usrwindow *ui;
};

#endif // USRWINDOW_H
