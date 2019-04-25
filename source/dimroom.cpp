#include "dimroom.h"
#include "ui_dimroom.h"
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
#include<QPalette>
#include<QPixmap>


extern hotelmanagerlist L2; //全局变量 酒店管理员链表
extern hotellist L3;        //酒店链表
extern roomlist L4;         //房间链表

dimroom::dimroom(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::dimroom)
{
    ui->setupUi(this);

    //按照路径将资源文件里的图片设为窗口背景，并自适应窗口大小
    QPalette pal;
    QPixmap pix = QPixmap(":/new/prefix1/mypicture/_20180801113455.jpg").scaled(this->size());
    pal.setBrush(QPalette::Background,QBrush(pix));
    this->setPalette(pal);
}

dimroom::~dimroom()
{
    delete ui;
}

void dimroom::on_dimbutton_clicked()
{
    Node<Hotelmanager> *p1 = L2.currPtr; //p1指向L2的当前结点
    Node<Room> *p2 = L4.front;           //p2指向L4的头结点
    int i = 0;

    //遍历L4，当酒店名和房间类型都符合时，删除当前结点
    while(p2 != nullptr)
    {
        if(p1->data.getHotelName() == p2->data.getRoomHol()&&ui->lineEdit->text() == p2->data.getRoomType())
        {
            L4.reset(i);
            L4.deleteCurrent();
            QMessageBox::information(NULL,"","删除成功",QMessageBox::Yes);
            return;
            this->close();
        }
        i++;                            //记录结点position，用于游标初始化
        p2 = p2->nextNode();            //p2指向后继结点
    }
    QMessageBox::information(NULL,"","您查找的房间不存在",QMessageBox::Yes);
}
