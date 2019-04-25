#include "sethotelwindow.h"
#include "ui_sethotelwindow.h"
#include"hotellist.h"
#include"node.h"
#include"holtel.h"
#include"hotelmanagerlist.h"
#include"hotelmanager.h"
#include<QMessageBox>
#include<QStringLiteral>
#include<QString>
#include<QPalette>
#include<QPixmap>

extern hotellist L3;
extern hotelmanagerlist L2;
sethotelwindow::sethotelwindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::sethotelwindow)
{
    ui->setupUi(this);

    //设置窗口背景
    QPalette pal;
    QPixmap pix = QPixmap(":/new/prefix1/mypicture/_20180801113455.jpg").scaled(this->size());
    pal.setBrush(QPalette::Background,QBrush(pix));
    this->setPalette(pal);
}

sethotelwindow::~sethotelwindow()
{
    delete ui;
}

void sethotelwindow::on_pushButton_clicked()
{
    //从窗口填写信息读出数据并初始化对象
    Holtel hol;
    hol.setHotelname(ui->lineEdit->text());
    hol.setHotelplace(ui->lineEdit_2->text());
    hol.setHoteltel(ui->lineEdit_3->text());
    hol.setscore(0);
    hol.setpermitted(true);
    hol.setnumofscore(0);
    for(int i = 0;i<L3.size;i++)         //遍历酒店链表，判断是否酒店已被注册
    {
        Node<Holtel> *p = L3.front;
        if(ui->lineEdit->text() == p->data.getHotelname())
        {
            QMessageBox msg;
            msg.setText(QStringLiteral("该酒店已注册！"));
            msg.setWindowTitle(QStringLiteral("Error"));
            msg.exec();return;          //若被注册，则直接返回
        }
        p = p->nextNode();

    }

    QString tel = ui->lineEdit_3->text();
    if(tel.length() != 11)
    {
        QMessageBox::information(NULL,"","电话号码不正确",QMessageBox::Yes);
        return;
    }

    L3.insertRear(hol);
    Node<Hotelmanager> *p1 = L2.currPtr;
    p1->data.setHotelName(ui->lineEdit->text());
    QMessageBox msg;
    msg.setText(QStringLiteral("酒店创建成功！"));
    msg.setWindowTitle(QStringLiteral("Success"));
    msg.exec();
    this->close();

}

void sethotelwindow::on_change_clicked()
{
    Node<Hotelmanager> *p = L2.currPtr;
    Node<Holtel>  *p1 = L3.front;
    while (p1 != nullptr)
    {
        if(p1->data.getHotelname() == p->data.getHotelName())
        {
            p1->data.setHotelplace(ui->lineEdit_5->text());
            p1->data.setHoteltel(ui->lineEdit_6->text());
            QMessageBox::information(NULL,"","修改成功",QMessageBox::Yes);
            this->close();
            return;
            break;
        }
        p1 = p1->nextNode();

    }

}
