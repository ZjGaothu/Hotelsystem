#include "manageorderwindow.h"
#include "ui_manageorderwindow.h"
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

//全局变量
extern customerlist L1;
extern orderlist L5;
extern roomlist L4;
extern hotelmanagerlist L2;

manageorderwindow::manageorderwindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::manageorderwindow)
{
    ui->setupUi(this);
    //设置背景
    QPalette pal;
    QPixmap pix = QPixmap(":/new/prefix1/mypicture/_20180801113455.jpg").scaled(this->size());
    pal.setBrush(QPalette::Background,QBrush(pix));
    this->setPalette(pal);

    //初始化表头
    QStringList header;
    ui->tableWidget->setColumnCount(6);
    header<<tr("订单号")<<tr("酒店名称")<<tr("房间类型")<<tr("房间价格")<<tr("入住日期")<<tr("入住天数");
    ui->tableWidget->setHorizontalHeaderLabels(header);

    //设置tablewidget行数
    Node<Hotelmanager> *p2 = L2.currPtr;
    orderlist ord;
    ord = L5.searchbyhotel(p2->data.getHotelName());     //按照酒店名搜索订单
    orderlist right;
    right = ord.searchbyispaid();                        //搜索已支付订单
    int sum = right.getSize();
    ui->tableWidget->setRowCount(sum);                   //设置行数

    Node<Order> *p1 = right.front;
    for(int i = 0;i<sum;i++)                             //遍历将订单显示在表中
    {
        QString s1 = QString("%1").arg(p1->data.getmoney());
        Date d = p1->data.getstartdate();
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
        p1=p1->nextNode();
    }
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

    //设置另一表头
    QStringList header1;
    ui->tableWidget_2->setColumnCount(6);
    header1<<tr("订单号")<<tr("酒店名称")<<tr("房间类型")<<tr("房间价格")<<tr("入住日期")<<tr("入住天数");
    ui->tableWidget_2->setHorizontalHeaderLabels(header1);

    Node<Hotelmanager> *q = L2.currPtr;
    orderlist ord1;
    ord1 = L5.searchbyhotel(q->data.getHotelName());       //按照酒店名查找订单
    orderlist right1;
    right1 = ord1.searchbynopaid();                        //找出未付款订单
    int sum1 = right1.getSize();
    ui->tableWidget_2->setRowCount(sum1);
    Node<Order> *p3 = right1.front;
    for(int i = 0;i<sum1;i++)                              //遍历新链表将数据显示在表中
    {
        QString s11=QString("%1").arg(p3->data.getmoney());
        Date d1=p3->data.getstartdate();
        QString year1=QString::number(d1.getyear());
        QString month1=QString::number(d1.getmonth());
        QString day1=QString::number(d1.getday());
        QString s21=year1+"-"+month1+"-"+day1;
        QString s31=QString::number(p3->data.getdaylong());

        //依次将链表中内容放入表中
        ui->tableWidget_2->setItem(i,0,new QTableWidgetItem(QString::number(p3->data.getorderid())));
        ui->tableWidget_2->setItem(i,1,new QTableWidgetItem(p3->data.getHotelname()));
        ui->tableWidget_2->setItem(i,2,new QTableWidgetItem(p3->data.getRoomType()));
        ui->tableWidget_2->setItem(i,3,new QTableWidgetItem(s11));
        ui->tableWidget_2->setItem(i,4,new QTableWidgetItem(s21));
        ui->tableWidget_2->setItem(i,5,new QTableWidgetItem(s31));
        p3 = p3->nextNode();
    }
    ui->tableWidget_2->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget_2->setEditTriggers(QAbstractItemView::NoEditTriggers);

}

manageorderwindow::~manageorderwindow()
{
    delete ui;
}

void manageorderwindow::on_paybak_clicked()
{
    int a = ui->tableWidget->currentRow();
    Node<Order> *ord1 = L5.front;
    Node<Customer> *cus = L1.currPtr;

    //遍历找到选中的订单，根据订单号查找
    while(ord1 != nullptr)
    {
        if(QString::number(ord1->data.getorderid())==ui->tableWidget->item(a,0)->text())
        {
            Node<Room> *p2 = L4.front;
            for(int i = 0;i<L4.size;i++)
            {
                if(p2->data.getRoomHol() == ord1->data.getHotelname()&&p2->data.getRoomType() == ord1->data.getRoomType())
                {
                    int a = p2->data.getRoomnum();
                    a = a+1;                             //房间余量加一
                    p2->data.setRoomnum(a);
                    break;
                }
                p2 = p2->nextNode();
            }
            float money = cus->data.gettreasure();
            float back = ord1->data.getmoney();
            money += back;                              //账户余额返回
            cus->data.settreasure(money);
            ord1->data.setispaid(false);
            break;
        }
        ord1 = ord1->nextNode();
    }
    QMessageBox::information(NULL,"","退款成功",QMessageBox::Yes);
    this->close();
}
