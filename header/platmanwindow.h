#ifndef PLATMANWINDOW_H
#define PLATMANWINDOW_H

#include <QWidget>

namespace Ui {
class platmanwindow;
}

class platmanwindow : public QWidget
{
    Q_OBJECT

public:
    explicit platmanwindow(QWidget *parent = 0);
    ~platmanwindow();

private slots:
    void on_dim_clicked();

    void on_deletethis_clicked();

    void on_passbutton_clicked();

private:
    Ui::platmanwindow *ui;
};

#endif // PLATMANWINDOW_H
