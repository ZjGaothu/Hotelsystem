#include "sendmessagewindow.h"
#include "ui_sendmessagewindow.h"
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
#include<QPalette>
#include<QPixmap>

extern customerlist L1;
extern orderlist L5;
extern roomlist L4;
extern messagelist L6;

sendmessagewindow::sendmessagewindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::sendmessagewindow)
{
    ui->setupUi(this);

    QPalette pal;
    QPixmap pix = QPixmap(":/new/prefix1/mypicture/_20180801113455.jpg").scaled(this->size());
    pal.setBrush(QPalette::Background,QBrush(pix));
    this->setPalette(pal);
}

sendmessagewindow::~sendmessagewindow()
{
    delete ui;
}

void sendmessagewindow::on_yestosend_clicked()
{
    QString receiveid = ui->lineEdit->text();
    Node<Customer> *p1 = L1.front;
    int i = 0;

    //遍历查找用户，如果用户i指在表尾，则return，即不存在该用户
    for(i = 0;i<L1.size;i++)
    {
        if(p1->data.getID() == receiveid)
        {
            break;
        }
        p1 = p1->nextNode();
    }
    if(i == L1.getSize())
    {
        QMessageBox::information(NULL,"","不存在该用户",QMessageBox::Yes);
        return;
    }

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
