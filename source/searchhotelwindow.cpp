#include "searchhotelwindow.h"
#include "ui_searchhotelwindow.h"
#include<QString>
#include<QStringLiteral>
#include<QTableWidgetItem>
#include"hotellist.h"
#include"hotelmanagerlist.h"
#include"node.h"
#include"linkedlist.h"
#include<QString>
#include<QStringLiteral>
#include"roomlist.h"
#include<QMessageBox>
#include<QTableWidget>
#include"dimroom.h"
#include"customerlist.h"
#include<QButtonGroup>
#include"makeorder.h"
#include<QPalette>
#include<QPixmap>

extern customerlist L1;
extern hotelmanagerlist L2;
extern hotellist L3;
extern roomlist L4;

searchhotelwindow::searchhotelwindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::searchhotelwindow)
{
    ui->setupUi(this);

    //设置窗口背景
    QPalette pal;
    QPixmap pix = QPixmap(":/new/prefix1/mypicture/_20180801113455.jpg").scaled(this->size());
    pal.setBrush(QPalette::Background,QBrush(pix));
    this->setPalette(pal);
}

searchhotelwindow::~searchhotelwindow()
{
    delete ui;
}

void searchhotelwindow::on_pushButton_clicked()
{
     //在buttongroup新增radiobutton
     QButtonGroup *bg = new QButtonGroup();
     bg->addButton(ui->hotelplace,0);
     bg->addButton(ui->roomtype,1);
     bg->addButton(ui->hotelname,2);
     int a = bg->checkedId();   //得到选中的radiobutton
     switch (a)
     {
     case 0:
     {
         //此情况不可按照价格排序，价格排序按钮不可点击
         ui->sortbyprice->setEnabled(false);
         ui->sortbycomments->setEnabled(true);

         //设置表头
         QStringList header;
         ui->tableWidget->setColumnCount(4);
         header<<tr("酒店名称")<<tr("酒店位置")<<tr("联系电话")<<tr("评分");
         ui->tableWidget->setHorizontalHeaderLabels(header);

         int sum = 0;
         hotellist placeout = L3.searchbyplace(ui->lineEdit->text());
         hotellist placeout1 = placeout.searchbypermitted();
         sum = placeout1.getSize(); //获取挑选出新链表的元素个数
         ui->tableWidget->setRowCount(sum);
         Node<Holtel> *p = placeout1.front;
         //遍历将链表放在表中显示
         for(int i = 0;i<sum;i++)
         {
             QString s1 = QString("%1").arg(p->data.getscore());
             ui->tableWidget->setItem(i,0,new QTableWidgetItem(p->data.getHotelname()));
             ui->tableWidget->setItem(i,1,new QTableWidgetItem(p->data.getHotelplace()));
             ui->tableWidget->setItem(i,2,new QTableWidgetItem(p->data.getHoteltel()));
             ui->tableWidget->setItem(i,3,new QTableWidgetItem(s1));
             p = p->nextNode();
         }
         break;
     }
     case 1:
     {
         //此情况为查看房间信息，因此按照评分排序按钮将不可点击
         ui->sortbycomments->setDisabled(true);
         ui->sortbyprice->setEnabled(true);

         //设置表头
         ui->tableWidget->setColumnCount(6);
         QStringList header;
         header<<tr("酒店名称")<<tr("房间类型")<<tr("房间价格")<<tr("房间余量")<<tr("优惠")<<tr("客房描述");
         ui->tableWidget->setHorizontalHeaderLabels(header);
         int sum1 = 0;
         roomlist roo = L4.searchbytype(ui->lineEdit->text());
         roomlist roo1 = roo.searchbypermitted();
         sum1 = roo1.getSize();
         ui->tableWidget->setRowCount(sum1);
         Node<Room> *p = roo1.front;
         for(int i = 0;i<sum1;i++)
         {
             QString s2 = QString("%1").arg(p->data.getRoomprice());
             QString s3 = QString("%1").arg(p->data.getDiscounts());
             QString s4 = QString::number(p->data.getRoomnum());
             ui->tableWidget->setItem(i,0,new QTableWidgetItem(p->data.getRoomHol()));
             ui->tableWidget->setItem(i,1,new QTableWidgetItem(p->data.getRoomType()));
             ui->tableWidget->setItem(i,2,new QTableWidgetItem(s2));
             ui->tableWidget->setItem(i,3,new QTableWidgetItem(s4));
             ui->tableWidget->setItem(i,4,new QTableWidgetItem(s3));
             ui->tableWidget->setItem(i,5,new QTableWidgetItem(p->data.getRoomDiscription()));
             p = p->nextNode();
         }
         break;
     }
     case 2:
     {
         //此情况不可按照价格排序，价格排序按钮不可点击
         ui->sortbyprice->setEnabled(false);
         ui->sortbycomments->setEnabled(false);
         //设置表头
         ui->tableWidget->setColumnCount(6);
         QStringList header;
         header<<tr("酒店名称")<<tr("房间类型")<<tr("房间价格")<<tr("房间余量")<<tr("优惠")<<tr("客房描述");
         ui->tableWidget->setHorizontalHeaderLabels(header);
         int sum1 = 0;
         roomlist roo = L4.searchbyhotel(ui->lineEdit->text());
         roomlist roo1 = roo.searchbypermitted();
         sum1 = roo1.getSize();
         ui->tableWidget->setRowCount(sum1);
         Node<Room> *p = roo1.front;
         for(int i = 0;i<sum1;i++)
         {
             QString s2 = QString("%1").arg(p->data.getRoomprice());
             QString s3 = QString("%1").arg(p->data.getDiscounts());
             QString s4 = QString::number(p->data.getRoomnum());
             ui->tableWidget->setItem(i,0,new QTableWidgetItem(p->data.getRoomHol()));
             ui->tableWidget->setItem(i,1,new QTableWidgetItem(p->data.getRoomType()));
             ui->tableWidget->setItem(i,2,new QTableWidgetItem(s2));
             ui->tableWidget->setItem(i,3,new QTableWidgetItem(s4));
             ui->tableWidget->setItem(i,4,new QTableWidgetItem(s3));
             ui->tableWidget->setItem(i,5,new QTableWidgetItem(p->data.getRoomDiscription()));
             p = p->nextNode();
         }
         break;

     }
     }

}

void searchhotelwindow::on_makeorder_clicked()
{
    makeorder *p = new makeorder;
    p->show();
}

void searchhotelwindow::on_sortbyprice_clicked()
{
    //设置表头
    ui->tableWidget->setColumnCount(6);
    QStringList header;
    header<<tr("酒店名称")<<tr("房间类型")<<tr("房间价格")<<tr("房间余量")<<tr("优惠")<<tr("客房描述");
    ui->tableWidget->setHorizontalHeaderLabels(header);

    //sum1用于获取roo的元素个数
    int sum1 = 0;
    roomlist roo = L4.searchbytype(ui->lineEdit->text());
    roomlist roo1 = roo.searchbypermitted();
    sum1 = roo1.getSize();
    ui->tableWidget->setRowCount(sum1);
    roo1.sortbyprice();                      //按照价格排序
    Node<Room> *p = roo1.front;
    for(int i = 0;i<sum1;i++)
    {
        QString s2 = QString("%1").arg(p->data.getRoomprice());
        QString s3 = QString("%1").arg(p->data.getDiscounts());
        QString s4 = QString::number(p->data.getRoomnum());
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(p->data.getRoomHol()));
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(p->data.getRoomType()));
        ui->tableWidget->setItem(i,2,new QTableWidgetItem(s2));
        ui->tableWidget->setItem(i,3,new QTableWidgetItem(s4));
        ui->tableWidget->setItem(i,4,new QTableWidgetItem(s3));
        ui->tableWidget->setItem(i,5,new QTableWidgetItem(p->data.getRoomDiscription()));
        p = p->nextNode();
    }
}

void searchhotelwindow::on_sortbycomments_clicked()
{
    QStringList header;
    ui->tableWidget->setColumnCount(4);
    header<<tr("酒店名称")<<tr("酒店位置")<<tr("联系电话")<<tr("评分");
    ui->tableWidget->setHorizontalHeaderLabels(header);

    int sum = 0;
    hotellist placeout = L3.searchbyplace(ui->lineEdit->text());
    hotellist placeout1 = placeout.searchbypermitted();
    sum = placeout1.getSize();
    ui->tableWidget->setRowCount(sum);
    placeout1.sortbyscore();                    //按照评分对新链表进行排序
    Node<Holtel> *p = placeout1.front;
    for(int i = 0;i<sum;i++)
    {
        QString s1 = QString("%1").arg(p->data.getscore());
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(p->data.getHotelname()));
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(p->data.getHotelplace()));
        ui->tableWidget->setItem(i,2,new QTableWidgetItem(p->data.getHoteltel()));
        ui->tableWidget->setItem(i,3,new QTableWidgetItem(s1));
        p=p->nextNode();
    }
}
