#include "messagewindow.h"
#include "ui_messagewindow.h"
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
#include"makescorewindow.h"
#include"messagelist.h"
#include"sendmessagewindow.h"
#include<QPalette>
#include<QPixmap>

extern messagelist L6;
extern customerlist L1;

messagewindow::messagewindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::messagewindow)
{
    ui->setupUi(this);

    //设置背景图片
    QPalette pal;
    QPixmap pix = QPixmap(":/new/prefix1/mypicture/_20180801113455.jpg").scaled(this->size());
    pal.setBrush(QPalette::Background,QBrush(pix));
    this->setPalette(pal);

    //初始化表头
    QStringList header;
    ui->tableWidget->setColumnCount(2);
    header<<tr("发送者账号")<<tr("消息");
    ui->tableWidget->setHorizontalHeaderLabels(header);


    Node<Customer> *p = L1.currPtr;
    messagelist mes;                                    //新建链表
    mes = L6.searchbyreceiveID(p->data.getID());        //按照接受者用户名查找消息
    int num = mes.getSize();
    ui->tableWidget->setRowCount(num);
    Node<Message> *p6 = mes.front;
    for(int i = 0;i<num;i++)                            //遍历输出
    {
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(p6->data.getsendID()));
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(p6->data.getmessage()));
        p6=p6->nextNode();
    }
    //列自适应大小
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    QHeaderView* headerView = ui->tableWidget->horizontalHeader();
    headerView->setSectionResizeMode(QHeaderView::Stretch);

    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);   //单击选择整行
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);    //不可编辑表中数据


    //初始化表头
    QStringList header1;
    ui->tableWidget_2->setColumnCount(2);
    header<<tr("接受者账号")<<tr("消息");
    ui->tableWidget_2->setHorizontalHeaderLabels(header1);

    Node<Customer> *p1 = L1.currPtr;
    messagelist mes1;                                    //新建链表
    mes1 = L6.searchbysendID(p1->data.getID());        //按照接受者用户名查找消息
    int num1 = mes1.getSize();
    ui->tableWidget_2->setRowCount(num1);
    Node<Message> *p61 = mes1.front;
    for(int i = 0;i<num1;i++)                            //遍历输出
    {
        ui->tableWidget_2->setItem(i,0,new QTableWidgetItem(p61->data.getreceiveID()));
        ui->tableWidget_2->setItem(i,1,new QTableWidgetItem(p61->data.getmessage()));
        p61=p61->nextNode();
    }
    ui->tableWidget_2->setEditTriggers(QAbstractItemView::NoEditTriggers);
    QHeaderView* headerView1 = ui->tableWidget_2->horizontalHeader();
    headerView1->setSectionResizeMode(QHeaderView::Stretch);
}

messagewindow::~messagewindow()
{
    delete ui;
}

void messagewindow::on_sendmessage_clicked()
{
    //新建发送消息的窗口
    sendmessagewindow *sen = new sendmessagewindow;
    sen->show();
}

void messagewindow::on_backmessage_clicked()
{
    int a = ui->tableWidget->currentRow();
    QString receiveid = ui->tableWidget->item(a,0)->text();


    //新建message对象 初始化后加在messagelist表尾
    Node<Customer> *p = L1.currPtr;
    QString sendid = p->data.getID();
    QString message = ui->textEdit->toPlainText();
    Message mes;
    mes.setreceiveID(receiveid);
    mes.setmessage(message);
    mes.setsendID(sendid);
    L6.insertRear(mes);
    QMessageBox::information(NULL,"","发送成功",QMessageBox::Yes);
    this->close();
}
