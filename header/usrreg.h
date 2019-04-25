#ifndef USRREG_H
#define USRREG_H

#include <QWidget>

namespace Ui {
class usrreg;
}

class usrreg : public QWidget
{
    Q_OBJECT

public:
    explicit usrreg(QWidget *parent = 0);
    ~usrreg();

private slots:
    void on_pushButton_clicked();

private:
    Ui::usrreg *ui;
};

#endif // USRREG_H
