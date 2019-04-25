#include "makeorder.h"
#include "ui_makeorder.h"
#include"node.h"
#include"linkedlist.h"
#include"orderlist.h"
#include"customer.h"
#include"customerlist.h"
#include<QString>
#include"date.h"
#include"hotellist.h"
#include"room.h"
#include"holtel.h"
#include"roomlist.h"
#include<QString>
#include<QMessageBox>
#include<QPalette>
#include<QPixmap>

//全局变量
extern customerlist L1;
extern hotellist L3;
extern roomlist L4;
extern orderlist L5;

makeorder::makeorder(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::makeorder)
{
    ui->setupUi(this);

    //设置背景图片
    QPalette pal;
    QPixmap pix = QPixmap(":/new/prefix1/mypicture/_20180801113455.jpg").scaled(this->size());
    pal.setBrush(QPalette::Background,QBrush(pix));
    this->setPalette(pal);
}

makeorder::~makeorder()
{
    delete ui;
}

void makeorder::on_yesorder_clicked()
{
    Node<Customer> *p = L1.currPtr;
    Node<Room> *p2 = L4.front;
    int j = 0;

    //判断是否遍历到表尾，如果是则返回，并提示填写信息有误
    for(j = 0;j<L4.getSize();j++)
    {
        if(p2->data.getRoomHol() == ui->nameline->text()&&p2->data.getRoomType() == ui->comboBox->currentText())
        {
            break;
        }
        p2=p2->nextNode();
    }
    if(j == L4.getSize())
    {
        QMessageBox::information(NULL,"","填写信息有误",QMessageBox::Yes);
        return;
    }

    //遍历roomlist链表，并初始化费用和折扣
    float money=0;
    float discount=0;
    for(int i = 0;i<L4.size;i++)
    {
        if(p2->data.getRoomHol() == ui->nameline->text()&&p2->data.getRoomType() == ui->comboBox->currentText())
        {
            money = p2->data.getRoomprice();  //获取单价费用
            discount = p2->data.getDiscounts();  //获取优惠
            int a = p2->data.getRoomnum();       //获取房间数
            if(a == 0)  //房间余量不足时
            {
                QMessageBox::information(NULL,"","房间余量不足",QMessageBox::Yes);
                return;
            }
            a = a-1;
            p2->data.setRoomnum(a);
            break;
        }
        p2 = p2->nextNode();          //指向下一结点
    }


    money = money-discount;         //单价减去优惠金额
    int daylong = ui->timeline->text().toInt();  //获得入住时长

    if(float(money*daylong)>p->data.gettreasure())  //判断是否可支付费用，如不能则返回
    {
        QMessageBox::information(NULL,"","您的余额不足",QMessageBox::Yes);
        return;
    }
    p2 = L4.front;                                   //从填写信息中依次初始化订单
    Order neworder;
    neworder.setcustomerid(p->data.getID());
    neworder.sethotelname(ui->nameline->text());
    neworder.setroomtype(ui->comboBox->currentText());
    int year = ui->dateEdit->date().year();
    int month = ui->dateEdit->date().month();
    int day = ui->dateEdit->date().day();
    Date newdate(year,month,day);                    //初始化入住日期
    neworder.setstartdate(newdate);

    int id = 1;
    Node<Order> *p5 = L5.front;                      //遍历找到最大订单号
    for(int j = 0;j<L5.size;j++)
    {
        if(id<p5->data.getorderid())
        {
            id = p5->data.getorderid();
        }
        p5 = p5->nextNode();
    }
    neworder.setdaylong(daylong);
    neworder.setmoney(money);
    neworder.setispaid(true);
    neworder.setorderid(id+1);                      //新订单号为最大订单号+1
    L5.insertRear(neworder);                        //在订单类链表表尾插入新结点
    QMessageBox::information(NULL,"","成功下单并付款成功",QMessageBox::Yes);
    p->data.Paymoney(float(money*daylong));
    this->close();
}
