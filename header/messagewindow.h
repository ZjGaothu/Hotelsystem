#ifndef MESSAGEWINDOW_H
#define MESSAGEWINDOW_H

#include <QWidget>

namespace Ui {
class messagewindow;
}

class messagewindow : public QWidget
{
    Q_OBJECT

public:
    explicit messagewindow(QWidget *parent = 0);
    ~messagewindow();

private slots:
    void on_sendmessage_clicked();

    void on_backmessage_clicked();

private:
    Ui::messagewindow *ui;
};

#endif // MESSAGEWINDOW_H
