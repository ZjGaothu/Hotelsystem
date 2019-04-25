#ifndef MANAGEROOMWINDOW_H
#define MANAGEROOMWINDOW_H

#include <QWidget>

namespace Ui {
class manageroomwindow;
}

class manageroomwindow : public QWidget
{
    Q_OBJECT

public:
    explicit manageroomwindow(QWidget *parent = 0);
    ~manageroomwindow();

private slots:
    void on_refresh_clicked();

    void on_deletebutton_clicked();

    void on_deletethis_clicked();

private:
    Ui::manageroomwindow *ui;
};

#endif // MANAGEROOMWINDOW_H
