#ifndef DIMHOTEL_H
#define DIMHOTEL_H

#include <QWidget>

namespace Ui {
class dimhotel;
}

class dimhotel : public QWidget
{
    Q_OBJECT

public:
    explicit dimhotel(QWidget *parent = 0);
    ~dimhotel();

private slots:
    void on_dimhol_clicked();

private:
    Ui::dimhotel *ui;
};

#endif // DIMHOTEL_H
