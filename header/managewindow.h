#ifndef MANAGEWINDOW_H
#define MANAGEWINDOW_H

#include <QWidget>

namespace Ui {
class managewindow;
}

class managewindow : public QWidget
{
    Q_OBJECT

public:
    explicit managewindow(QWidget *parent = 0);
    ~managewindow();

private slots:
    void on_save_clicked();

    void on_sethotel_clicked();

    void on_newroom_clicked();

    void on_viewwindow_clicked();

    void on_setroom_clicked();

    void on_manageorder_clicked();

private:
    Ui::managewindow *ui;
};

#endif // MANAGEWINDOW_H
