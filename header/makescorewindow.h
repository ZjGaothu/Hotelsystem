#ifndef MAKESCOREWINDOW_H
#define MAKESCOREWINDOW_H

#include <QWidget>

namespace Ui {
class makescorewindow;
}

class makescorewindow : public QWidget
{
    Q_OBJECT

public:
    explicit makescorewindow(QWidget *parent = 0);
    ~makescorewindow();

private slots:
    void on_yesbutton_clicked();

private:
    Ui::makescorewindow *ui;
};

#endif // MAKESCOREWINDOW_H
