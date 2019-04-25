#ifndef SEARCHHOTELWINDOW_H
#define SEARCHHOTELWINDOW_H

#include <QWidget>

namespace Ui {
class searchhotelwindow;
}

class searchhotelwindow : public QWidget
{
    Q_OBJECT

public:
    explicit searchhotelwindow(QWidget *parent = 0);
    ~searchhotelwindow();

private slots:
    void on_pushButton_clicked();

    void on_makeorder_clicked();

    void on_sortbyprice_clicked();

    void on_sortbycomments_clicked();

private:
    Ui::searchhotelwindow *ui;
};

#endif // SEARCHHOTELWINDOW_H
