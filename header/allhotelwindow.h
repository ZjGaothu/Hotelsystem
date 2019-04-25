#ifndef ALLHOTELWINDOW_H
#define ALLHOTELWINDOW_H
#include <QWidget>

namespace Ui {
class allhotelwindow;
}

class allhotelwindow : public QWidget
{
    Q_OBJECT

public:
    explicit allhotelwindow(QWidget *parent = 0);
    ~allhotelwindow();

private:
    Ui::allhotelwindow *ui;
};

#endif // ALLHOTELWINDOW_H
