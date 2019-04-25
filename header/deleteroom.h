#ifndef DELETEROOM_H
#define DELETEROOM_H

#include <QWidget>

namespace Ui {
class deleteroom;
}

class deleteroom : public QWidget
{
    Q_OBJECT

public:
    explicit deleteroom(QWidget *parent = 0);
    ~deleteroom();

private:
    Ui::deleteroom *ui;
};

#endif // DELETEROOM_H
