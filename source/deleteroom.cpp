#include "deleteroom.h"
#include "ui_deleteroom.h"

deleteroom::deleteroom(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::deleteroom)
{
    ui->setupUi(this);
}

deleteroom::~deleteroom()
{
    delete ui;
}
