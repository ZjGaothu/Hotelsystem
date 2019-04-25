#include "managewindow.h"
#include "ui_managewindow.h"
#include"mydatabase.h"
#include"newroomwindow.h"
#include"sethotelwindow.h"
#include"viewhotelwindow.h"
#include"changeholtelwindow.h"
#include"manageroomwindow.h"
#include"manageorderwindow.h"
#include<QPalette>
#include<QPixmap>

extern customerlist L1;
extern hotelmanagerlist L2;
extern hotellist L3;

managewindow::managewindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::managewindow)
{
    ui->setupUi(this);

    //设置背景
    QPalette pal;
    QPixmap pix = QPixmap(":/new/prefix1/mypicture/_20180801113455.jpg").scaled(this->size());
    pal.setBrush(QPalette::Background,QBrush(pix));
    this->setPalette(pal);
}

managewindow::~managewindow()
{
    delete ui;
}

void managewindow::on_save_clicked()
{
    //保存顾客类和酒店管理员链表
    myDatabase::saveCustomer(L1);
    myDatabase::savemanager(L2);
    this->close();
}



void managewindow::on_sethotel_clicked()
{
    sethotelwindow *hol = new sethotelwindow;
    hol->show();
}


void managewindow::on_newroom_clicked()
{
    //查看房间窗口
    manageroomwindow *newroom = new manageroomwindow;
    newroom->show();
}



void managewindow::on_viewwindow_clicked()
{
    //查看酒店窗口
    changeholtelwindow *p = new changeholtelwindow;
    p->show();
}

void managewindow::on_setroom_clicked()
{
    //新建房间窗口
    newroomwindow *p = new newroomwindow;
    p->show();
}


void managewindow::on_manageorder_clicked()
{
    //查看订单窗口
    manageorderwindow *ordwin = new manageorderwindow;
    ordwin->show();
}

