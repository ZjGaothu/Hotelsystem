#include "myorder.h"
#include "ui_myorder.h"
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
#include<QPalette>
#include<QPixmap>

//查看我的已付款订单

//全局变量
QString name;
extern customerlist L1;
extern orderlist L5;
extern roomlist L4;


myorder::myorder(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::myorder)
{
    ui->setupUi(this);
    //设置背景图片
    QPalette pal;
    QPixmap pix = QPixmap(":/new/prefix1/mypicture/_20180801113455.jpg").scaled(this->size());
    pal.setBrush(QPalette::Background,QBrush(pix));
    this->setPalette(pal);

    //初始化表头
    QStringList header;
    ui->tableWidget->setColumnCount(6);
    header<<tr("订单号")<<tr("酒店名称")<<tr("房间类型")<<tr("房间价格")<<tr("入住日期")<<tr("入住天数");
    ui->tableWidget->setHorizontalHeaderLabels(header);

    Node<Customer> *p = L1.currPtr;
    orderlist ord;
    ord = L5.searchbycusID(p->data.getID());   //按照顾客用户名查找订单
    orderlist right;
    right = ord.searchbyispaid();              //找出以上所有已付款订单
    int sum = right.getSize();
    ui->tableWidget->setRowCount(sum);         //初始化行数
    Node<Order> *p1 = right.front;
    for(int i = 0;i<sum;i++)
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
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);   //单击选择整行
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);    //不可编辑表中数据

}

myorder::~myorder()
{
    delete ui;
}



void myorder::on_refund_clicked()
{
    int a = ui->tableWidget->currentRow();     //获取选中行的行数
    Node<Order> *ord1 = L5.front;              //指向订单类的表头
    Node<Customer> *cus = L1.currPtr;          //指向顾客链表的当前顾客
    while(ord1 != nullptr)
    {
        if(QString::number(ord1->data.getorderid()) == ui->tableWidget->item(a,0)->text())   //根据订单号遍历
        {
            Node<Room> *p2 = L4.front;
            for(int i = 0;i<L4.size;i++)
            {
                if(p2->data.getRoomHol() == ord1->data.getHotelname()&&p2->data.getRoomType() == ord1->data.getRoomType())
                {
                    int a = p2->data.getRoomnum();
                    a = a+1;                          //房间数加一
                    p2->data.setRoomnum(a);           //重新设置房间余量
                    break;                            //跳出循环
                }
                p2 = p2->nextNode();
            }
            float money = cus->data.gettreasure();
            float back = ord1->data.getmoney();
            money += back;
            cus->data.settreasure(money);             //重新设置账户余额
            ord1->data.setispaid(false);
            break;
        }
        ord1 = ord1->nextNode();
    }
    QMessageBox::information(NULL,"","退款成功",QMessageBox::Yes);
    this->close();

}

void myorder::on_paybutton_clicked()
{
    makescorewindow *score1 = new makescorewindow;
    score1->show();
}

void myorder::on_scorebutton_clicked()
{
    //name为全局变量，评分界面为此酒店评分
    int current = ui->tableWidget->currentRow();
    name = ui->tableWidget->item(current,1)->text();
    makescorewindow *score1 = new makescorewindow;
    score1->show();
}

//修改顾客密码
void myorder::on_changepass_clicked()
{
    Node<Customer> *p1 = L1.currPtr;
    if(p1->data.getPassword() == ui->lineEdit->text()&&ui->lineEdit_2->text() == ui->lineEdit_3->text())
    {
        p1->data.changePassword(ui->lineEdit_2->text());
        QMessageBox::information(NULL,"","修改成功",QMessageBox::Yes);
        this->close();
        return;
    }
    QMessageBox::information(NULL,"","您输入的信息有误",QMessageBox::Yes);
}
