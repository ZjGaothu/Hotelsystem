#ifndef SETHOTELWINDOW_H
#define SETHOTELWINDOW_H

#include <QWidget>

namespace Ui {
class sethotelwindow;
}

class sethotelwindow : public QWidget
{
    Q_OBJECT

public:
    explicit sethotelwindow(QWidget *parent = 0);
    ~sethotelwindow();

private slots:
    void on_pushButton_clicked();

    void on_change_clicked();

private:
    Ui::sethotelwindow *ui;
};

#endif // SETHOTELWINDOW_H
