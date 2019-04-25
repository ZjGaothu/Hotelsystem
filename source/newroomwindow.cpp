#include "newroomwindow.h"
#include "ui_newroomwindow.h"
#include"hotellist.h"
#include"hotelmanagerlist.h"
#include"node.h"
#include"linkedlist.h"
#include<QString>
#include<QStringLiteral>
#include"roomlist.h"
#include<QMessageBox>
#include<QPalette>
#include<QPixmap>

//建立新房间

//全局变量
extern hotelmanagerlist L2;
extern hotellist L3;
extern roomlist L4;

newroomwindow::newroomwindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::newroomwindow)
{
    ui->setupUi(this);

    //设置窗口背景
    QPalette pal;
    QPixmap pix = QPixmap(":/new/prefix1/mypicture/_20180801113455.jpg").scaled(this->size());
    pal.setBrush(QPalette::Background,QBrush(pix));
    this->setPalette(pal);
}

newroomwindow::~newroomwindow()
{
    delete ui;
}

void newroomwindow::on_create_clicked()
{
    Node<Hotelmanager> *p = L2.currPtr;
    //以此获取窗口中所填信息
    QString hotelname = p->data.getHotelName();
    QString s1 = ui->comboBox->currentText();
    QString s2 = ui->roomprice->text();
    QString s3 = ui->roomsun->text();
    QString s4 = ui->discount->text();
    //将文本进行数据类型转换
    float n1 = s2.toFloat();
    int n2 = s3.toInt();
    float n3 = s4.toFloat();
    if(n2<=0)
    {
        QMessageBox::information(NULL,"","房间数至少为一",QMessageBox::Yes);
        return;
    }
    //用数据初始化对象并加在表尾
    Room newroom;
    newroom.setRoomHol(hotelname);
    newroom.setRoomType(s1);
    newroom.setRoomnum(n2);
    newroom.setRoomprice(n1);
    newroom.setRoomdiscount(n3);
    newroom.setRoomDiscription(ui->discription->text());
    L4.insertRear(newroom);
    QMessageBox::information(NULL,"","创建成功",QMessageBox::Yes);
    this->close();
}
