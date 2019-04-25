#ifndef DIMROOM_H
#define DIMROOM_H

#include <QWidget>

namespace Ui {
class dimroom;
}

class dimroom : public QWidget
{
    Q_OBJECT

public:
    explicit dimroom(QWidget *parent = 0);
    ~dimroom();

private slots:
    void on_dimbutton_clicked();

private:
    Ui::dimroom *ui;
};

#endif // DIMROOM_H
