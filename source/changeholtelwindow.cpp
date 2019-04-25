#include "changeholtelwindow.h"
#include "ui_changeholtelwindow.h"
#include"hotelmanagerlist.h"
#include"hotelmanager.h"
#include"mydatabase.h"
#include"mainwindow.h"
#include"node.h"
#include"linkedlist.h"
#include<QStringLiteral>
#include<QString>
#include"hotellist.h"
#include<QPalette>
#include<QPixmap>

extern hotelmanagerlist L2;
extern hotellist L3;

changeholtelwindow::changeholtelwindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::changeholtelwindow)
{
    ui->setupUi(this);
    //背景图片
    QPalette pal;
    QPixmap pix=QPixmap(":/new/prefix1/mypicture/_20180801113455.jpg").scaled(this->size()); //图片自适应窗口大小
    pal.setBrush(QPalette::Background,QBrush(pix));
    this->setPalette(pal);

    //读出当前酒店的信息
    Node<Holtel> *p1 = L3.front;
    Node<Hotelmanager> *p2 = L2.currPtr;
    for(int i = 0;i<L3.size;i++)                   //遍历查找
    {
        if(p2->data.getHotelName() == p1->data.getHotelname())
        {
           ui->lineEdit->setText(p1->data.getHotelname());
           ui->lineEdit_2->setText(p1->data.getHotelplace());
           ui->lineEdit_3->setText(p1->data.getHoteltel());
           ui->lineEdit_4->setText(QString::number(p1->data.getscore()));
           if(p1->data.getpermitted())
           {
               ui->lineEdit_8->setText(QStringLiteral("通过"));
           }
           else ui->lineEdit_8->setText(QStringLiteral("未通过"));
        }
        p1 = p1->nextNode();
        }
}

changeholtelwindow::~changeholtelwindow()
{
    delete ui;
}


void changeholtelwindow::on_freshbutton_clicked()
{
    Node<Holtel> *p1 = L3.front;                    //再次遍历查找
    Node<Hotelmanager> *p2 = L2.currPtr;
    for(int i = 0;i<L3.size;i++)
    {
        if(p2->data.getHotelName() == p1->data.getHotelname())
        {
           ui->lineEdit->setText(p1->data.getHotelname());
           ui->lineEdit_2->setText(p1->data.getHotelplace());
           ui->lineEdit_3->setText(p1->data.getHoteltel());
           ui->lineEdit_4->setText(QString::number(p1->data.getscore()));
        }
        p1 = p1->nextNode();
    }
}

//修改酒店管理员密码
void changeholtelwindow::on_changepass_clicked()
{
    Node<Hotelmanager> *p2 = L2.currPtr;
    if(p2->data.getPassword() == ui->lineEdit_5->text()&&ui->lineEdit_6->text() == ui->lineEdit_7->text())
    {
        p2->data.changePassword(ui->lineEdit_6->text());
        QMessageBox::information(NULL,"","修改成功",QMessageBox::Yes);
        this->close();
        return;
    }
    QMessageBox::information(NULL,"","您输入的信息有误",QMessageBox::Yes);
}

