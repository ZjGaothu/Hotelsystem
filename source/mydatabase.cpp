#include "mydatabase.h"
#include"customer.h"
#include"linkedlist.h"
#include"node.h"
#include<QSqlDatabase>
#include<QSqlQuery>
#include"mainwindow.h"
#include"customerlist.h"
#include"hotelmanagerlist.h"
#include<QDebug>
#include"roomlist.h"
#include"orderlist.h"
#include"date.h"
#include"message.h"
#include"messagelist.h"

extern customerlist L1;
extern hotelmanagerlist L2;
extern hotellist L3;
extern roomlist L4;
extern orderlist L5;

myDatabase::myDatabase()
{
    createConnection();

}
 myDatabase::~myDatabase(){
}
void myDatabase::createConnection(){
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("Hotelsystem.db");    //设置数据库名称
    db.setUserName("Hotelsystem");
    db.setPassword("123456");
    db.open();
    if(!db.open()){
        QMessageBox msg;
        msg.setText(QStringLiteral("打开数据库失败！"));
        msg.setWindowTitle(QStringLiteral("警告！"));
        msg.exec();}
    QSqlQuery query;
    //为Customer类创建表
    query.exec("create table if not exists mmyyCustomers(ID varchar(20),"
               "Password varchar(20),IDNumber varchar(20),treasure float);");

    //为Hotelmanager类创建表
    query.exec("create table if not exists mmyyHotelmanagers(ID varchar(20),"
               "Password varchar(20),HotelName varchar(20));");

    //为Holtel类创建表
    query.exec("create table if not exists mmyyHoltels(Hotelname varchar(20),"
               "Hotelplace varchar(20),Hoteltel varchar(20),Ispermitted integer,"
               "score float,numofscore integer);");

    //为Room类创建表
    query.exec("create table if not exists mmyyRooms(RoomType varchar(20),"
               "RoomHol varchar(20),Roomprice float,Discounts float,RoomDiscription varchar(60),Roomnum integer);");

    //为Order类创建表
    query.exec("create table if not exists mmyyOrdersss(Hotelname varchar(20),Roomtype varchar(20),"
               "customerid varchar(20),money float,Startyear integer,Startmonth integer,Startday integer,"
               "dayslong integer,ispaid integer,orderid integer);");

    //为Message类创建表
    query.exec("create table if not exists mmyyMessage(sendID varchar(20),"
               "receiveID varchar(20),message varchar(100));");

    db.close();
}
void myDatabase::initialCustomer(customerlist &L1){//打开数据库初始化顾客链表
    QSqlDatabase db = QSqlDatabase::database();
    db.open();
    QSqlQuery query;
    query.exec("select * from mmyyCustomers");       //从表中调取数据
    while(query.next())
    {
        //从数据库依次读出数据并初始化Customer对象
        Customer c(query.value(0).toString(),query.value(1).toString(),query.value(2).toString(),query.value(3).toFloat());
        L1.insertRear(c);
    }
    query.clear();
}

void myDatabase::saveCustomer(customerlist &L1){ //最终将顾客链表保存在数据库
    QSqlDatabase db = QSqlDatabase::database();
    db.open();
    QSqlQuery query;
    query.exec("delete from mmyyCustomers");        //清空表格
    QString In = "insert into mmyyCustomers values(";  //sql语句，在表格中插入数据
    Node<Customer> *p1 = L1.front;                   //遍历链表插入数据
    while(p1 != nullptr)
    {
        QString L1In = In+"'"+p1->data.getID()+"','"+p1->data.getPassword()+"','"+p1->data.getIDNumber()+"',"+QString::number(p1->data.gettreasure())+");";
        query.exec(L1In);
        p1 = p1->nextNode();
    }
}

void myDatabase::initialmanager(hotelmanagerlist &L2) //初始化酒店管理员链表
{
    QSqlDatabase db = QSqlDatabase::database();
    db.open();
    QSqlQuery query;
    query.exec("select * from mmyyHotelmanagers");  //从表中调取数据
    while(query.next())                           //初始化链表
    {
        QString id = query.value(0).toString();
        QString Password = query.value(1).toString();
        Hotelmanager h(id,Password);
        h.setHotelName(query.value(2).toString());
        L2.insertRear(h);                       //表尾插入数据
    }
    query.clear();
}

void myDatabase::savemanager(hotelmanagerlist &L2) //将酒店管理员链表数据保存在数据库
{
    QSqlDatabase db = QSqlDatabase::database();
    db.open();
    QSqlQuery query;
    query.exec("delete from mmyyHotelmanagers");    //清空表
    QString In = "insert into mmyyHotelmanagers values(";
    Node<Hotelmanager> *p2 = L2.front;
    while(p2 != nullptr)
    {
        QString L2In = In+"'"+p2->data.getID()+"','"+p2->data.getPassword()+"','"+p2->data.getHotelName()+"');";
        query.exec(L2In);
        p2 = p2->nextNode();
    }
}

void myDatabase::initialhotel(hotellist &L3)  //初始化酒店链表
{
    QSqlDatabase db = QSqlDatabase::database();
    db.open();
    QSqlQuery query;
    query.exec("select * from mmyyHoltels");
    while(query.next())
    {
        Holtel hol(query.value(0).toString(),query.value(1).toString(),query.value(2).toString());
        int a = query.value(3).toInt();
        if(a == 0)                       //将布尔类型以integer型存入数据库，读出时进行判断
        {
            hol.setpermitted(false);
        }
        else
        {
            hol.setpermitted(true);
        }
        hol.setscore(query.value(4).toFloat());
        hol.setnumofscore(query.value(5).toInt());
        L3.insertRear(hol);
    }
    query.clear();
}


void myDatabase::savehotel(hotellist &L3)  //将酒店链表数据保存在数据库
{
    QSqlDatabase db = QSqlDatabase::database();
    db.open();
    QSqlQuery query;
    query.exec("delete from mmyyHoltels");
    QString In = "insert into mmyyHoltels values(";
    Node<Holtel> *p3 = L3.front;
    while (p3 != nullptr)
    {
        QString L3In = In+"'"+p3->data.getHotelname()+"','"+p3->data.getHotelplace()+"','"+p3->data.getHoteltel()+"',";
        if(p3->data.getpermitted())
        {
            L3In = L3In+"1,";
        }
        else L3In = L3In+"0,";
        L3In = L3In+QString::number(p3->data.getscore())+","+QString::number(p3->data.getnumofscore())+");";
        query.exec(L3In);
        p3=p3->nextNode();
    }
}

void myDatabase::initialroom(roomlist &L4) //初始化房间链表
{
    QSqlDatabase db = QSqlDatabase::database();
    db.open();
    QSqlQuery query;
    query.exec("select * from mmyyRooms");
    while(query.next())
    {
        Room roo;
        roo.setRoomType(query.value(0).toString());
        roo.setRoomHol(query.value(1).toString());
        roo.setRoomprice(query.value(2).toFloat());
        roo.setRoomdiscount(query.value(3).toFloat());
        roo.setRoomDiscription(query.value(4).toString());
        roo.setRoomnum(query.value(5).toInt());
        L4.insertRear(roo);
    }
    query.clear();
}

void myDatabase::saveroom(roomlist &L4)  //将房间链表数据保存在数据库
{
    QSqlDatabase db = QSqlDatabase::database();
    db.open();
    QSqlQuery query;
    query.exec("delete from mmyyRooms");
    QString In = "insert into mmyyRooms values(";
    Node<Room> *p4 = L4.front;
    while(p4 != nullptr)
    {
        QString L4In = In+"'"+p4->data.getRoomType()+"','"+p4->data.getRoomHol()+"',";
        L4In = L4In+QString::number(p4->data.getRoomprice())+","+QString::number(p4->data.getDiscounts());
        L4In = L4In+",'"+p4->data.getRoomDiscription()+"',"+QString::number(p4->data.getRoomnum())+");";
        query.exec(L4In);
        p4 = p4->nextNode();
    }
}

void myDatabase::initialorder(orderlist &L5)  //初始化订单链表
{
    QSqlDatabase db = QSqlDatabase::database();
    db.open();
    QSqlQuery query;
    query.exec("select * from mmyyOrdersss");
    while(query.next())                       //初始化订单对象 并插入订单链表表尾
    {
        Order ord;
        ord.sethotelname(query.value(0).toString());
        ord.setroomtype(query.value(1).toString());
        ord.setcustomerid(query.value(2).toString());
        ord.setmoney(query.value(3).toFloat());
        Date d(query.value(4).toInt(),query.value(5).toInt(),query.value(6).toInt());
        ord.setstartdate(d);
        ord.setdaylong(query.value(7).toInt());
        int a = query.value(8).toInt();
        if(a == 0)
        {
            ord.setispaid(false);
        }
        else if(a == 1)
        {
            ord.setispaid(true);
        }
        ord.setorderid(query.value(9).toInt());
        L5.insertRear(ord);
    }
    query.clear();
}


void myDatabase::saveorder(orderlist &L5)  //将订单链表数据保存在数据库中
{
    QSqlDatabase db = QSqlDatabase::database();
    db.open();
    QSqlQuery query;
    query.exec("delete from mmyyOrdersss");
    QString In = "insert into mmyyOrdersss values(";
    Node<Order> *p5 = L5.front;
    while (p5 != nullptr)
    {
        QString L5In = In+"'"+p5->data.getHotelname()+"','"+p5->data.getRoomType()+"','"+p5->data.getcustomerid()+"',";
        L5In = L5In+QString::number(p5->data.getmoney())+",";
        Date dd = p5->data.getstartdate();
        L5In = L5In+QString::number(dd.getyear())+","+QString::number(dd.getmonth())+","+QString::number(dd.getday())+",";
        L5In = L5In+QString::number(p5->data.getdaylong())+",";
        if(p5->data.getispaid())
        {
            L5In = L5In+"1,"+QString::number(p5->data.getorderid())+");";
        }
        else L5In = L5In+"0,"+QString::number(p5->data.getorderid())+");";
        query.exec(L5In);
        p5=p5->nextNode();
    }
}

void myDatabase::initialmessage(messagelist &L6)
{
    QSqlDatabase db = QSqlDatabase::database();
    db.open();
    QSqlQuery query;
    query.exec("select * from mmyyMessage");
    while(query.next())
    {
        Message mes;
        mes.setsendID(query.value(0).toString());
        mes.setreceiveID(query.value(1).toString());
        mes.setmessage(query.value(2).toString());
        L6.insertRear(mes);
    }
    query.clear();
}

void myDatabase::savemessage(messagelist &L6)
{
    QSqlDatabase db = QSqlDatabase::database();
    db.open();
    QSqlQuery query;
    query.exec("delete from mmyyMessage");
    QString In = "insert into mmyyMessage values(";
    Node<Message> *p6 = L6.front;
    while(p6 != nullptr)
    {
        QString L6In = In+"'"+p6->data.getsendID()+"','"+p6->data.getreceiveID()+"','"+p6->data.getmessage()+"');";
        query.exec(L6In);
        p6=p6->nextNode();
    }
}
