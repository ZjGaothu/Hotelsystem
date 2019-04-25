#include "mybackorderwindow.h"
#include "ui_mybackorderwindow.h"
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
#include"orderlist.h"
#include<QPalette>
#include<QPixmap>

//我的退款订单窗口
//全局变量
extern customerlist L1;
extern orderlist L5;
extern roomlist L4;

mybackorderwindow::mybackorderwindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mybackorderwindow)
{
    ui->setupUi(this);

    //设置窗口背景图片
    QPalette pal;
    QPixmap pix = QPixmap(":/new/prefix1/mypicture/_20180801113455.jpg").scaled(this->size());
    pal.setBrush(QPalette::Background,QBrush(pix));
    this->setPalette(pal);

    //初始化表头
    QStringList header;
    ui->tableWidget->setColumnCount(6);
    header<<tr("订单号")<<tr("酒店名称")<<tr("房间类型")<<tr("房间价格")<<tr("入住日期")<<tr("入住天数");
    ui->tableWidget->setHorizontalHeaderLabels(header);

    Node<Customer> *p = L1.currPtr;                        //p指向当前结点
    orderlist ord;
    ord = L5.searchbycusID(p->data.getID());               //初始化ord
    orderlist right;
    right = ord.searchbynopaid();                          //查找出该用户未付款订单
    int sum = right.getSize();
    ui->tableWidget->setRowCount(sum);
    Node<Order> *p1 = right.front;
    for(int i = 0;i<sum;i++)
    {
        QString s1=QString("%1").arg(p1->data.getmoney());   //将费用转化成字符串型
        Date d=p1->data.getstartdate();
        QString year = QString::number(d.getyear());
        QString month = QString::number(d.getmonth());
        QString day = QString::number(d.getday());
        QString s2 = year+"-"+month+"-"+day;
        QString s3 = QString::number(p1->data.getdaylong());
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(QString::number(p1->data.getorderid())));
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(p1->data.getHotelname()));
        ui->tableWidget->setItem(i,2,new QTableWidgetItem(p1->data.getRoomType()));
        ui->tableWidget->setItem(i,3,new QTableWidgetItem(s1));
        ui->tableWidget->setItem(i,4,new QTableWidgetItem(s2));
        ui->tableWidget->setItem(i,5,new QTableWidgetItem(s3));
        p1 = p1->nextNode();
    }
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);  //设置单击选中行
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);   //设置表中数据不可编辑
}

mybackorderwindow::~mybackorderwindow()
{
    delete ui;
}
