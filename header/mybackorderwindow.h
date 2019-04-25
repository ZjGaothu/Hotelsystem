#ifndef MYBACKORDERWINDOW_H
#define MYBACKORDERWINDOW_H

#include <QWidget>

namespace Ui {
class mybackorderwindow;
}

class mybackorderwindow : public QWidget
{
    Q_OBJECT

public:
    explicit mybackorderwindow(QWidget *parent = 0);
    ~mybackorderwindow();

private:
    Ui::mybackorderwindow *ui;
};

#endif // MYBACKORDERWINDOW_H
