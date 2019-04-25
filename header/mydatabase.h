#ifndef MYDATABASE_H
#define MYDATABASE_H
#include <QObject>
#include<Qtsql/QSqlDatabase>
#include<QtSql/QSqlQuery>
#include<QtSql/QSqlDriver>
#include<QtSql/QSqlError>
#include<QtSql/QSqlRecord>
#include<QtSql/QSqlTableModel>
#include<QtDebug>
#include<QtSql/QSqlField>
#include<QMessageBox>
#include<QStringLiteral>
#include"customerlist.h"
#include"hotelmanagerlist.h"
#include"holtel.h"
#include"hotellist.h"
#include"roomlist.h"
#include"orderlist.h"
#include"messagelist.h"

//数据库类
//初始化链表，连接数据库，并把链表数据存入数据库

class myDatabase
{
public:
    myDatabase();
    ~myDatabase();
    QSqlDatabase db;
public:
       static void initialCustomer(customerlist &L1);        //初始化顾客链表
       static void saveCustomer(customerlist &L1);           //保存顾客链表数据至数据库
       static void initialmanager(hotelmanagerlist &L2);     //初始化酒店管理员
       static void savemanager(hotelmanagerlist &L2);        //保存酒店管理员链表至数据库
       static void initialhotel(hotellist &L3);              //初始化酒店链表
       static void savehotel(hotellist &L3);                 //保存酒店数据至数据库
       static void initialroom(roomlist &L4);                //初始化房间链表
       static void saveroom(roomlist &L4);                   //保存房间链表至数据库
       static void initialorder(orderlist &L5);              //初始化订单链表
       static void saveorder(orderlist &L5);                 //保存订单数据至数据库
       static void initialmessage(messagelist &L6);          //初始化消息链表
       static void savemessage(messagelist &L6);             //保存消息至数据库
       static void createConnection();                       //创建与数据库链接并创建表
};

#endif // MYDATABASE_H
