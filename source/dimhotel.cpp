#include "dimhotel.h"
#include "ui_dimhotel.h"
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
#include"order.h"
#include"orderlist.h"
#include<QMessageBox>
#include<QTableWidget>
#include<QPalette>
#include<QPixmap>


extern hotelmanagerlist L2;  //酒店管理员链表
extern hotellist L3;       //酒店链表
extern roomlist L4;        //房间链表
extern orderlist L5;       //订单链表

dimhotel::dimhotel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::dimhotel)
{
    ui->setupUi(this);
    //设置背景图片
    QPalette pal;
    QPixmap pix=QPixmap(":/new/prefix1/mypicture/_20180801113455.jpg").scaled(this->size());
    pal.setBrush(QPalette::Background,QBrush(pix));
    this->setPalette(pal);
}

dimhotel::~dimhotel()
{
    delete ui;
}

void dimhotel::on_dimhol_clicked()
{
    Node<Holtel> *p = L3.front;                  //p3指向L3头结点
    int i = 0;                                   //记录指针所指position
    QString hotelname;
    while(p != nullptr)                          //遍历链表并删除酒店
    {
        if(p->data.getHotelname() == ui->lineEdit->text())
        {
            p->data.setpermitted(false);
            hotelname = p->data.getHotelname();
            QMessageBox::information(NULL,"","删除成功",QMessageBox::Yes);
            this->close();
            return;
        }
        i++;
        p = p->nextNode();
    }

    //如果未找到此酒店，则弹出提示框
    QMessageBox::information(NULL,"","您查找的酒店不存在",QMessageBox::Yes);
}
