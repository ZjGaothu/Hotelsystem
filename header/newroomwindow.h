#ifndef NEWROOMWINDOW_H
#define NEWROOMWINDOW_H

#include <QWidget>

namespace Ui {
class newroomwindow;
}

class newroomwindow : public QWidget
{
    Q_OBJECT

public:
    explicit newroomwindow(QWidget *parent = 0);
    ~newroomwindow();

private slots:
    void on_create_clicked();

private:
    Ui::newroomwindow *ui;
};

#endif // NEWROOMWINDOW_H
