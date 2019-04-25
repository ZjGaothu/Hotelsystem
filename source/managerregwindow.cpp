#include "managerregwindow.h"
#include "ui_managerregwindow.h"
#include<QMessageBox>
#include"hotelmanagerlist.h"
#include"hotelmanager.h"
#include"mydatabase.h"
#include"mainwindow.h"
#include"node.h"
#include"linkedlist.h"
#include<QStringLiteral>
#include<QString>
#include"hotellist.h"
#include"roomlist.h"
#include"orderlist.h"
#include"messagelist.h"
#include<QPalette>
#include<QPixmap>

//全局变量的声明
customerlist L1;
hotelmanagerlist L2;
hotellist L3;
roomlist L4;
orderlist L5;
messagelist L6;



managerregwindow::managerregwindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::managerregwindow)
{
    ui->setupUi(this);

    //设置背景
    QPalette pal;
    QPixmap pix = QPixmap(":/new/prefix1/mypicture/_20180801113455.jpg").scaled(this->size());
    pal.setBrush(QPalette::Background,QBrush(pix));
    this->setPalette(pal);
}

managerregwindow::~managerregwindow()
{
    delete ui;
}

void managerregwindow::on_pushButton_clicked()
{
    if(ui->passline->text() != ui->repassline->text())
    {
        QMessageBox::information(NULL,"ERROR","The password do not match!",QMessageBox::Yes);
        return ;
    }

    for(int i = 0;i<L2.size;i++)       //遍历查找，不允许同一用户名重复注册
    {
        Node<Hotelmanager> *p2 = L2.front;
        if(ui->idline->text() == p2->data.getID())
        {
            QMessageBox msg;
            msg.setText(QStringLiteral("该账号已注册！"));
            msg.setWindowTitle(QStringLiteral("Error"));
            msg.exec();return;
        }
        p2 = p2->nextNode();

    }
    Hotelmanager newmanager(ui->idline->text(),ui->passline->text()); //构造新对象并初始化
    L2.insertRear(newmanager);       //在酒店管理员表尾插入新结点
    QMessageBox msg;
    msg.setText(QStringLiteral("管理员注册成功！"));
    msg.setWindowTitle(QStringLiteral("Success"));
    msg.exec();
    this->close();
}
