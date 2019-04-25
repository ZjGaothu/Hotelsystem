#include "manageroomwindow.h"
#include "ui_manageroomwindow.h"
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
#include"dimroom.h"
#include<QPalette>
#include<QPixmap>

extern hotelmanagerlist L2;
extern hotellist L3;
extern roomlist L4;

manageroomwindow::manageroomwindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::manageroomwindow)
{
    ui->setupUi(this);

    //设置背景
    QPalette pal;
    QPixmap pix = QPixmap(":/new/prefix1/mypicture/_20180801113455.jpg").scaled(this->size());
    pal.setBrush(QPalette::Background,QBrush(pix));
    this->setPalette(pal);

    Node<Hotelmanager> *p1 = L2.currPtr;  //p1指向L2当前结点
    Node<Room> *p2 = L4.front;            //p2指向L4即roomlist头结点
    int i = 1;
    while (p2)                            //遍历找到酒店名符合的结点，并将数据依次填入表中
    {
      if(p1->data.getHotelName() == p2->data.getRoomHol())
      {
          ui->tableWidget->setItem(i,0,new QTableWidgetItem(p2->data.getRoomType()));
          ui->tableWidget->setItem(i,1,new QTableWidgetItem(QString::number(p2->data.getRoomprice())));
          ui->tableWidget->setItem(i,2,new QTableWidgetItem(QString::number(p2->data.getRoomnum())));
          ui->tableWidget->setItem(i,3,new QTableWidgetItem(QString::number(p2->data.getDiscounts())));
          ui->tableWidget->setItem(i,4,new QTableWidgetItem(p2->data.getRoomDiscription()));
          i++;
      }
      p2 = p2->nextNode();
    }

    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);   //单击选择整行
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);    //不可编辑表中数据
}

manageroomwindow::~manageroomwindow()
{
    delete ui;
}

void manageroomwindow::on_refresh_clicked()   //更新操作，将数据更新后依次填入表中
{
    Node<Hotelmanager> *p1 = L2.currPtr;
    Node<Room> *p2 = L4.front;
    int i = 1;
    while (p2)
    {
      if(p1->data.getHotelName() == p2->data.getRoomHol())
      {
          ui->tableWidget->setItem(i,0,new QTableWidgetItem(p2->data.getRoomType()));
          ui->tableWidget->setItem(i,1,new QTableWidgetItem(QString::number(p2->data.getRoomprice())));
          ui->tableWidget->setItem(i,2,new QTableWidgetItem(QString::number(p2->data.getRoomnum())));
          ui->tableWidget->setItem(i,3,new QTableWidgetItem(QString::number(p2->data.getDiscounts())));
          ui->tableWidget->setItem(i,4,new QTableWidgetItem(p2->data.getRoomDiscription()));
          i++;
      }
      p2 = p2->nextNode();
    }
}

void manageroomwindow::on_deletebutton_clicked()
{
    dimroom *dim = new dimroom;
    dim->show();
}

void manageroomwindow::on_deletethis_clicked()
{

    int a = ui->tableWidget->currentRow();
    QString Roomtype = ui->tableWidget->item(a,0)->text();
    Node<Hotelmanager> *p1 = L2.currPtr; //p1指向L2的当前结点
    Node<Room> *p2 = L4.front;           //p2指向L4的头结点
    int i = 0;

    //遍历L4，当酒店名和房间类型都符合时，删除当前结点
    while(p2 != nullptr)
    {
        if(p1->data.getHotelName() == p2->data.getRoomHol()&&Roomtype == p2->data.getRoomType())
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
}
