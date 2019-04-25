#ifndef CHANGEHOLTELWINDOW_H
#define CHANGEHOLTELWINDOW_H

#include <QWidget>

namespace Ui {
class changeholtelwindow;
}

class changeholtelwindow : public QWidget
{
    Q_OBJECT

public:
    explicit changeholtelwindow(QWidget *parent = 0);
    ~changeholtelwindow();

private slots:
    void on_freshbutton_clicked();

    void on_changepass_clicked();

private:
    Ui::changeholtelwindow *ui;
};

#endif // CHANGEHOLTELWINDOW_H
