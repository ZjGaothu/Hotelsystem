#include "makescorewindow.h"
#include "ui_makescorewindow.h"
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

extern QString name;
makescorewindow::makescorewindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::makescorewindow)
{
    ui->setupUi(this);

    //设置背景
    QPalette pal;
    QPixmap pix = QPixmap(":/new/prefix1/mypicture/_20180801113455.jpg").scaled(this->size());
    pal.setBrush(QPalette::Background,QBrush(pix));
    this->setPalette(pal);
}

makescorewindow::~makescorewindow()
{
    delete ui;
}

void makescorewindow::on_yesbutton_clicked()
{
    Node<Holtel> *p = L3.front;
    for(int i = 0;i<L3.getSize();i++)                 //遍历使p指向当前酒店结点
    {
        if(p->data.getHotelname() == name)
        {
            break;
        }
        p = p->nextNode();
    }
    float score = p->data.getscore();                 //获取酒店评分
    int num = p->data.getnumofscore();                //获取总评分数量
    float newscore = ui->lineEdit->text().toFloat();  //从窗口中获取新输入分数
    if(newscore<0||newscore>10)                       //容错设计，使用户输入分数在相应范围内
    {
        QMessageBox::information(NULL,"","您输入的分数不在范围内",QMessageBox::Yes);
        return;
    }


    score = float(score*num)+newscore;                //计算总分
    num = num+1;                                      //评分数加一
    score = float(score/num);                         //得到平均分
    p->data.setscore(score);                          //初始化评分
    p->data.setnumofscore(num);                       //初始化评分数
    QMessageBox::information(NULL,"","评分成功",QMessageBox::Yes);
    this->close();
}
