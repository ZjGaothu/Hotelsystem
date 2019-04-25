#include "platmanwindow.h"
#include "ui_platmanwindow.h"
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
#include<QPalette>
#include<QPixmap>

//管理员界面
extern customerlist L1;
extern hotelmanagerlist L2;
extern hotellist L3;

platmanwindow::platmanwindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::platmanwindow)
{
    ui->setupUi(this);

    //设置背景图片
    QPalette pal;
    QPixmap pix = QPixmap(":/new/prefix1/mypicture/_20180801113455.jpg").scaled(this->size());
    pal.setBrush(QPalette::Background,QBrush(pix));
    this->setPalette(pal);

    //设置表头显示所有酒店
    QStringList header;
    header<<tr("酒店名称")<<tr("酒店位置")<<tr("联系电话")<<tr("评分")<<tr("评分数");
    ui->tableWidget->setHorizontalHeaderLabels(header);

    hotellist hoo = L3.searchbypermitted();
    ui->tableWidget->setRowCount(hoo.getSize());
    Node<Holtel> *p = hoo.front;
    int i = 0;           //记录行数
    while(p)
    {
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(p->data.getHotelname()));
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(p->data.getHotelplace()));
        ui->tableWidget->setItem(i,2,new QTableWidgetItem(p->data.getHoteltel()));
        ui->tableWidget->setItem(i,3,new QTableWidgetItem(QString::number(p->data.getscore())));
        ui->tableWidget->setItem(i,4,new QTableWidgetItem(QString::number(p->data.getnumofscore())));
        i++;
        p = p->nextNode();
    }

    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);   //单击选择整行
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);    //不可编辑表中数据
    ui->tableWidget_2->setSelectionBehavior(QAbstractItemView::SelectRows);   //单击选择整行
    ui->tableWidget_2->setEditTriggers(QAbstractItemView::NoEditTriggers);    //不可编辑表中数据


    //设置表头显示所有酒店
    QStringList header1;
    header1<<tr("酒店名称")<<tr("酒店位置")<<tr("联系电话")<<tr("评分")<<tr("评分数");
    ui->tableWidget_2->setHorizontalHeaderLabels(header1);
    hotellist hol1 = L3.searchbynopermitted();
    ui->tableWidget_2->setRowCount(hol1.getSize());
    Node<Holtel> *p1 = hol1.front;
    int a = 0;           //记录行数
    while(p1)
    {
        ui->tableWidget_2->setItem(a,0,new QTableWidgetItem(p1->data.getHotelname()));
        ui->tableWidget_2->setItem(a,1,new QTableWidgetItem(p1->data.getHotelplace()));
        ui->tableWidget_2->setItem(a,2,new QTableWidgetItem(p1->data.getHoteltel()));
        ui->tableWidget_2->setItem(a,3,new QTableWidgetItem(QString::number(p1->data.getscore())));
        ui->tableWidget_2->setItem(a,4,new QTableWidgetItem(QString::number(p1->data.getnumofscore())));
        a++;
        p1 = p1->nextNode();
    }
}

platmanwindow::~platmanwindow()
{
    delete ui;
}

void platmanwindow::on_dim_clicked()
{
    //跳转到删除房间的界面
    dimhotel *dimhol = new dimhotel;
    dimhol->show();
}

void platmanwindow::on_deletethis_clicked()
{
    int a = ui->tableWidget->currentRow();
    QString s1 = ui->tableWidget->item(a,0)->text();
    Node<Holtel> *p = L3.front;                  //p指向L3头结点
    int i = 0;                                   //记录指针所指position
    while(p != nullptr)                          //遍历链表并删除酒店
    {
        if(p->data.getHotelname() == s1)
        {
            p->data.setpermitted(false);
            QMessageBox::information(NULL,"","删除成功",QMessageBox::Yes);
            this->close();
            return;
        }
        i++;
        p = p->nextNode();
    }

    //如果未找到此酒店，则弹出提示框
    QMessageBox::information(NULL,"","您查找的酒店不存在",QMessageBox::Yes);

}

void platmanwindow::on_passbutton_clicked()
{
    int a = ui->tableWidget_2->currentRow();
    QString s1 = ui->tableWidget_2->item(a,0)->text();
    Node<Holtel> *p = L3.front;
    int i = 0;
    while(p != nullptr)
    {
        if(p->data.getHotelname() == s1)
        {
            p->data.setpermitted(true);
            QMessageBox::information(NULL,"","审核通过",QMessageBox::Yes);
            this->close();
            return;
        }
        i++;
        p = p->nextNode();
    }
}
