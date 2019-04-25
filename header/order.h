#ifndef ORDER_H
#define ORDER_H
#include<QString>
#include"date.h"
//订单类
//存储订单信息


class Order
{
private:
    QString Hotelname;         //订单的酒店名
    QString RoomType;          //订单的房间类型
    static int OrderNum;       //订单数
    float money;               //订单费用
    Date startdate;            //入住日期
    QString customerid;        //顾客用户名
    int days;                  //入住天数
    bool ispaid;               //是否支付
    int OrderID;               //订单号 用于区分订单

public:
    Order(){}
    Order(QString Hotelname1, QString RoomType1, float money1) :Hotelname(Hotelname1), RoomType(RoomType1), money(money1)
    {
        OrderNum++;
    }
    ~Order(){}

    friend class HotelManager;
    friend class Customer;
    friend class Date;

    void setorderid(int id);          //初始化订单号
    void setcustomerid(QString id);   //初始化顾客用户名
    void setispaid(bool ispaid1);     //初始化是否支付
    void setstartdate(Date &a);       //初始化入住日期
    void sethotelname(QString name);  //初始化酒店名
    void setroomtype(QString type);   //初始化房间类型
    void setmoney(float money1);      //初始化费用
    void setdaylong(int day);         //初始化入住天数

    float getmoney();                              //返回费用
    bool getispaid(){return ispaid;}               //返回是否支付
    Date getstartdate(){return startdate;}         //返回入住日期
    QString getHotelname(){return Hotelname;}      //返回酒店名
    QString getRoomType(){return RoomType;}        //返回房间类型
    QString getcustomerid(){return customerid;}    //返回顾客用户名
    int getdaylong(){return days;}                 //返回入住天数
    int getorderid(){return OrderID;}              //返回订单号

};

#endif // ORDER_H
