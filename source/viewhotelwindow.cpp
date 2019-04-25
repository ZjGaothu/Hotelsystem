#include "viewhotelwindow.h"
#include "ui_viewhotelwindow.h"
#include"hotellist.h"
#include"hotelmanagerlist.h"
#include<QString>
#include"node.h"
#include"linkedlist.h"
#include<QStringLiteral>
#include<QMessageBox>
#include"holtel.h"
#include"hotelmanager.h"

extern hotelmanagerlist L2;
extern hotellist L3;

viewhotelwindow::viewhotelwindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::viewhotelwindow)
{
    ui->setupUi(this);
}
viewhotelwindow::~viewhotelwindow()
{
    delete ui;
}
