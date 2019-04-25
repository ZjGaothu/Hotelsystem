#ifndef MAKEORDER_H
#define MAKEORDER_H

#include <QWidget>

namespace Ui {
class makeorder;
}

class makeorder : public QWidget
{
    Q_OBJECT

public:
    explicit makeorder(QWidget *parent = 0);
    ~makeorder();

private slots:
    void on_yesorder_clicked();

private:
    Ui::makeorder *ui;
};

#endif // MAKEORDER_H
