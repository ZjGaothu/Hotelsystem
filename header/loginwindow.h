#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QDialog>

namespace Ui {
class Loginwindow;
}

class Loginwindow : public QDialog
{
    Q_OBJECT

public:
    explicit Loginwindow(QWidget *parent = 0);
    ~Loginwindow();

private slots:
    void on_usrregbutton_clicked();

    void on_longinbuton_clicked();

    void on_holregbutton_clicked();

    void on_exitbuttom_clicked();


private:
    Ui::Loginwindow *ui;
};

#endif // LOGINWINDOW_H
