#include "allhotelwindow.h"
#include "ui_allhotelwindow.h"
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

extern customerlist L1;                 //顾客类链表全局变量
extern hotelmanagerlist L2;             //酒店管理员链表全局变量
extern hotellist L3;                    //酒店链表 全局变量
extern roomlist L4;                     //房间链表 全局变量

allhotelwindow::allhotelwindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::allhotelwindow)
{
    ui->setupUi(this);

    //设置背景图片自适应窗口大小
    QPalette pal;
    QPixmap pix = QPixmap(":/new/prefix1/mypicture/_20180801113455.jpg").scaled(this->size());
    pal.setBrush(QPalette::Background,QBrush(pix));
    this->setPalette(pal);

    //设置表头
    QStringList header;
    ui->tableWidget->setColumnCount(5);
    header<<tr("酒店名称")<<tr("酒店位置")<<tr("联系电话")<<tr("评分")<<tr("评分数");
    ui->tableWidget->setHorizontalHeaderLabels(header);

    //依次初始化两表行数
    hotellist hol = L3.searchbypermitted();
    Node<Holtel> *p = hol.front;
    roomlist roo = L4.searchbypermitted();
    ui->tableWidget->setRowCount(hol.size);
    ui->tableWidget_2->setRowCount(roo.size);

    //遍历将数据读入表中
    int i=0;
    while (p)
    {
        QString s1=QString("%1").arg(p->data.getscore());
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(p->data.getHotelname()));
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(p->data.getHotelplace()));
        ui->tableWidget->setItem(i,2,new QTableWidgetItem(p->data.getHoteltel()));
        ui->tableWidget->setItem(i,3,new QTableWidgetItem(s1));
        ui->tableWidget->setItem(i,4,new QTableWidgetItem(QString::number(p->data.getnumofscore())));
        p = p->nextNode();
        i++;
    }

    //初始化房间表表头
    ui->tableWidget_2->setColumnCount(6);
    QStringList header1;
    header1<<tr("酒店名称")<<tr("房间类型")<<tr("房间价格")<<tr("房间余量")<<tr("优惠")<<tr("客房描述");
    ui->tableWidget_2->setHorizontalHeaderLabels(header1);

    Node<Room> *p2 = roo.front;
    int x=0;
    while(p2)
    {
        QString s2=QString("%1").arg(p2->data.getRoomprice());
        QString s3=QString("%1").arg(p2->data.getDiscounts());
        QString s4=QString::number(p2->data.getRoomnum());
        ui->tableWidget_2->setItem(x,0,new QTableWidgetItem(p2->data.getRoomHol()));
        ui->tableWidget_2->setItem(x,1,new QTableWidgetItem(p2->data.getRoomType()));
        ui->tableWidget_2->setItem(x,2,new QTableWidgetItem(s2));
        ui->tableWidget_2->setItem(x,3,new QTableWidgetItem(s4));
        ui->tableWidget_2->setItem(x,4,new QTableWidgetItem(s3));
        ui->tableWidget_2->setItem(x,5,new QTableWidgetItem(p2->data.getRoomDiscription()));
        p2=p2->nextNode();
        x++;
    }

}

allhotelwindow::~allhotelwindow()
{
    delete ui;
}
