#include "usrwindow.h"
#include "ui_usrwindow.h"
#include<QString>
#include<QStringLiteral>
#include<QTableWidgetItem>
#include"hotellist.h"
#include"hotelmanagerlist.h"
#include"node.h"
#include"linkedlist.h"
#include<QString>
#include<QStringLiteral>
#include"roomlist.h"
#include<QMessageBox>
#include<QTableWidget>
#include"customerlist.h"
#include"rechargewindow.h"
#include"searchhotelwindow.h"
#include"allhotelwindow.h"
#include"myorder.h"
#include"mybackorderwindow.h"
#include"messagewindow.h"
#include<QPalette>
#include<QPixmap>
#include"changepasswindow.h"
#include"usrreg.h"

//顾客进入的主界面


extern customerlist L1;
extern hotelmanagerlist L2;
extern hotellist L3;
extern roomlist L4;

usrwindow::usrwindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::usrwindow)
{
    ui->setupUi(this);

    //设置背景图片
    QPalette pal;
    QPixmap pix = QPixmap(":/new/prefix1/mypicture/_20180801113455.jpg").scaled(this->size());
    pal.setBrush(QPalette::Background,QBrush(pix));
    this->setPalette(pal);

    //界面左上角显示该顾客的用户名 下方显示余额
    Node<Customer> *p = L1.currPtr;
    QString s1 = QString("%1").arg(p->data.gettreasure());
    ui->lineEdit->setText(s1);             //设置文本为用户名
    ui->cusid->setText(p->data.getID());   //显示余额
}

usrwindow::~usrwindow()
{
    delete ui;
}

//充值界面
void usrwindow::on_recharge_clicked()
{
    rechargewindow *charge = new rechargewindow;
    charge->show();
}

//查找酒店界面
void usrwindow::on_searchbutton_clicked()
{
    searchhotelwindow *search = new searchhotelwindow;
    search->show();
}

//查看酒店界面
void usrwindow::on_viewbutton_clicked()
{
    allhotelwindow *all = new allhotelwindow;
    all->show();
}

//我的订单界面
void usrwindow::on_myorder_clicked()
{
    myorder *myord = new myorder;
    myord->show();
}


//我的退款订单界面
void usrwindow::on_payback_clicked()
{
    mybackorderwindow *back = new mybackorderwindow;
    back->show();
}

//消息界面
void usrwindow::on_message_clicked()
{
    messagewindow *mess=new messagewindow;
    mess->show();
}

//修改密码界面
void usrwindow::on_pushButton_clicked()
{

}
