#ifndef VIEWHOTELWINDOW_H
#define VIEWHOTELWINDOW_H

#include <QWidget>

namespace Ui {
class viewhotelwindow;
}

class viewhotelwindow : public QWidget
{
    Q_OBJECT

public:
    explicit viewhotelwindow(QWidget *parent = 0);
    ~viewhotelwindow();

private:
    Ui::viewhotelwindow *ui;
};

#endif // VIEWHOTELWINDOW_H
