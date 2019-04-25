#include "picturewindow.h"
#include "ui_picturewindow.h"

picturewindow::picturewindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::picturewindow)
{
    ui->setupUi(this);
}

picturewindow::~picturewindow()
{
    delete ui;
}
