#ifndef SENDMESSAGEWINDOW_H
#define SENDMESSAGEWINDOW_H

#include <QWidget>

namespace Ui {
class sendmessagewindow;
}

class sendmessagewindow : public QWidget
{
    Q_OBJECT

public:
    explicit sendmessagewindow(QWidget *parent = 0);
    ~sendmessagewindow();

private slots:
    void on_yestosend_clicked();

private:
    Ui::sendmessagewindow *ui;
};

#endif // SENDMESSAGEWINDOW_H
