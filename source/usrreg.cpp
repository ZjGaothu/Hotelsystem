#include "usrreg.h"
#include "ui_usrreg.h"
#include<QString>
#include<QMessageBox>
#include"mainwindow.h"
#include"customerlist.h"
#include<qstringliteral.h>
#include<QStringLiteral>
#include"customer.h"
#include"mydatabase.h"
#include"node.h"

//顾客注册界面
extern customerlist L1;

usrreg::usrreg(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::usrreg)
{
    ui->setupUi(this);
    //设置背景图片
    QPalette pal;
    QPixmap pix = QPixmap(":/new/prefix1/mypicture/_20180801113455.jpg").scaled(this->size());
    pal.setBrush(QPalette::Background,QBrush(pix));
    this->setPalette(pal);
}

usrreg::~usrreg()
{
    delete ui;
}

void usrreg::on_pushButton_clicked()
{
    QString s1;
    s1 = ui->idline->text();

    //用户名不能为空
    if(ui->usrline->text().isEmpty())
    {
        QMessageBox::information(NULL,"","用户名不能为空",QMessageBox::Yes);
        return;
    }
    //两次输入密码必须保持一致
    if(ui->passline->text() != ui->repassline->text())                        //若两次密码不一致
    {
        QMessageBox::information(NULL,"ERROR","两次输入密码不一致",QMessageBox::Yes);
        return ;
    }
    //身份证审核需要为18位
    else if(s1.length() != 18)                                                //身份证号不是十八位则报错
    {
        QMessageBox::information(NULL,"ERROR","身份证号不符合要求",QMessageBox::Yes);
        return ;
    }

    //查找是否该用户已经注册过 不允许同一用户名或身份证号注册两次
    for(int i = 0;i<L1.size;i++)
    {
        Node<Customer> *p1=L1.front;
        if(ui->usrline->text() == p1->data.getID()||ui->idline->text() == p1->data.getIDNumber())
        {
            QMessageBox msg;
            msg.setText(QStringLiteral("该顾客已注册！"));
            msg.setWindowTitle(QStringLiteral("Error"));
            msg.exec();return;
        }
        p1 = p1->nextNode();

    }
    Customer newcustomer(ui->usrline->text(), ui->passline->text(), ui->idline->text(), 0);
    L1.insertRear(newcustomer);
    QMessageBox msg;
    msg.setText(QStringLiteral("顾客注册成功！"));
    msg.setWindowTitle(QStringLiteral("Success"));
    msg.exec();
    this->close();

}
