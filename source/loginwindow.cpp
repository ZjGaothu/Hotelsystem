#include "loginwindow.h"
#include "ui_loginwindow.h"
#include"usrreg.h"
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
#include<QButtonGroup>
#include"managewindow.h"
#include"platmanwindow.h"
#include"usrwindow.h"
#include"hotellist.h"
#include"orderlist.h"
#include<QPalette>
#include<QPixmap>
#include"picturewindow.h"

extern customerlist L1;
extern hotelmanagerlist L2;
extern hotellist L3;
extern roomlist L4;
extern orderlist L5;
extern messagelist L6;


Loginwindow::Loginwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Loginwindow)
{
    //连接数据库并将六个全局变量链表一次性初始化
    myDatabase::createConnection();
    myDatabase::initialCustomer(L1);
    myDatabase::initialmanager(L2);
    myDatabase::initialhotel(L3);
    myDatabase::initialroom(L4);
    myDatabase::initialorder(L5);
    myDatabase::initialmessage(L6);
    ui->setupUi(this);
    //设置背景
    QPalette pal;
    QPixmap pix = QPixmap(":/new/prefix4/mypicture1/_20180802220215.jpg").scaled(this->size());
    pal.setBrush(QPalette::Background,QBrush(pix));
    this->setPalette(pal);

}

Loginwindow::~Loginwindow()
{
    delete ui;
}

void Loginwindow::on_usrregbutton_clicked()
{

    //顾客注册界面
    usrreg *usrreg1 = new usrreg;
    usrreg1->show();
}

void Loginwindow::on_longinbuton_clicked()
{
    Node<Customer> *p1 = L1.front;
    Node<Hotelmanager> *p2 = L2.front;
    //将三个radiobutton加入group并赋初值
    QButtonGroup *bg = new QButtonGroup();
    bg->addButton(ui->radioButton,0);
    bg->addButton(ui->radioButton_2,1);
    bg->addButton(ui->radioButton_3,2);
    //判别所选中的radiobutton
    int a = bg->checkedId();
    switch (a)
    {
case 0:           //选中顾客登录
    {
    for(int i = 0;i<L1.getSize();i++)
    {
        //账号密码登录
        if(ui->usrline->text() == p1->data.getID()&&ui->passline->text() == p1->data.getPassword())
        {
          L1.currPtr = p1;     //将游标指向当前结点
          usrwindow *usr = new usrwindow;
          usr->show();
          return;
        }

        //使用身份证号登录
        if(ui->usrline->text() == p1->data.getIDNumber()&&ui->passline->text() == p1->data.getPassword())
        {
            L1.currPtr = p1;   //游标指向当前结点
            usrwindow *usr = new usrwindow;
            usr->show();
            return;
        }
        p1 = p1->nextNode();
    }
    QMessageBox msg;                                //登录未成功下，弹出messagebox
    msg.setText(QStringLiteral("用户名或密码不正确"));
    msg.setWindowTitle(QStringLiteral("Error"));
    msg.exec();return;
    break;
    }
case 1:            //酒店管理员登录
    {
       for(int i = 0;i<L2.size;i++)
       {
           if(ui->usrline->text() == p2->data.getID()&&ui->passline->text() == p2->data.getPassword())
           {
               L2.currPtr = p2;
               managewindow *man = new managewindow;
               man->show();
               return;
           }
           p2 = p2->nextNode();
       }
       QMessageBox msg;
       msg.setText(QStringLiteral("用户名或密码不正确"));
       msg.setWindowTitle(QStringLiteral("Error"));
       msg.exec();
       break;
    }
case 2:  //平台管理员登录
    {
        if(ui->usrline->text() == "123456"&&ui->passline->text()=="123456")
        {
            platmanwindow *pla = new platmanwindow;
            pla->show();break;
        }
        QMessageBox msg;
        msg.setText(QStringLiteral("用户名或密码不正确"));
        msg.setWindowTitle(QStringLiteral("Error"));
        msg.exec();
        break;

    }
default:
    {
        break;
    }

    }
}




void Loginwindow::on_holregbutton_clicked()
{
    //弹出酒店管理员注册窗口
    managerregwindow *man1 = new managerregwindow;
    man1->show();
}


void Loginwindow::on_exitbuttom_clicked()
{
    //退出程序时，将六个链表的数据一次性存入数据库
    myDatabase::saveCustomer(L1);
    myDatabase::savemanager(L2);
    myDatabase::savehotel(L3);
    myDatabase::saveroom(L4);
    myDatabase::saveorder(L5);
    myDatabase::savemessage(L6);
    this->close();
}


