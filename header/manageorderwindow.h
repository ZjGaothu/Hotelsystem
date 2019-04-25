#ifndef MANAGEORDERWINDOW_H
#define MANAGEORDERWINDOW_H

#include <QWidget>

namespace Ui {
class manageorderwindow;
}

class manageorderwindow : public QWidget
{
    Q_OBJECT

public:
    explicit manageorderwindow(QWidget *parent = 0);
    ~manageorderwindow();

private slots:
    void on_paybak_clicked();

private:
    Ui::manageorderwindow *ui;
};

#endif // MANAGEORDERWINDOW_H
