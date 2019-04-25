#ifndef MANAGERREGWINDOW_H
#define MANAGERREGWINDOW_H

#include <QWidget>

namespace Ui {
class managerregwindow;
}

class managerregwindow : public QWidget
{
    Q_OBJECT

public:
    explicit managerregwindow(QWidget *parent = 0);
    ~managerregwindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::managerregwindow *ui;
};

#endif // MANAGERREGWINDOW_H
