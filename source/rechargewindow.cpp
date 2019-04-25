#include "rechargewindow.h"
#include "ui_rechargewindow.h"
#include<QTableWidget>
#include<QString>
#include<QMessageBox>
#include"mainwindow.h"
#include"customerlist.h"
#include<qstringliteral.h>
#include<QStringLiteral>
#include"customer.h"
#include"mydatabase.h"
#include"node.h"
#include"managerregwindow.h"
#include"managewindow.h"
#include"platmanwindow.h"
#include"usrwindow.h"
#include"hotellist.h"
#include<QStringList>
#include"dimhotel.h"
#include<QPalette>
#include<QPixmap>

//充值界面

//全局变量链表
extern customerlist L1;
extern hotelmanagerlist L2;
extern hotellist L3;

rechargewindow::rechargewindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::rechargewindow)
{
    ui->setupUi(this);

    //设置背景图片
    QPalette pal;
    QPixmap pix = QPixmap(":/new/prefix1/mypicture/_20180801113455.jpg").scaled(this->size());
    pal.setBrush(QPalette::Background,QBrush(pix));
    this->setPalette(pal);
}

rechargewindow::~rechargewindow()
{
    delete ui;
}

void rechargewindow::on_charge_clicked()
{
    Node<Customer> *p1 = L1.currPtr;
    QString s1 = ui->lineEdit->text();
    if(ui->lineEdit_2->text() != p1->data.getPassword())      //输入密码进行验证
    {
        QMessageBox::information(NULL,"","密码错误",QMessageBox::Yes);
        return;
    }
    float charge = s1.toFloat();                             //强制转换为float型
    p1->data.recharge(charge);
    QMessageBox::information(NULL,"","充值成功",QMessageBox::Yes);
    this->close();
}
