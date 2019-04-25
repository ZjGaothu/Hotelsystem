#ifndef PICTUREWINDOW_H
#define PICTUREWINDOW_H

#include <QWidget>

namespace Ui {
class picturewindow;
}

class picturewindow : public QWidget
{
    Q_OBJECT

public:
    explicit picturewindow(QWidget *parent = 0);
    ~picturewindow();

private:
    Ui::picturewindow *ui;
};

#endif // PICTUREWINDOW_H
