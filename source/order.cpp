#include "order.h"

float Order::getmoney()
{
    return money;
}


void Order::setstartdate(Date &a)
{
    this->startdate=a;
}



void Order::setcustomerid(QString id)
{
    this->customerid=id;
}

void Order::sethotelname(QString name)
{
    this->Hotelname=name;
}

void Order::setroomtype(QString type)
{
    this->RoomType=type;
}

void Order::setmoney(float money1)
{
    this->money=money1;
}

void Order::setdaylong(int day)
{
    this->days=day;
}

void Order::setispaid(bool ispaid1)
{
    this->ispaid=ispaid1;
}

void Order::setorderid(int id)
{
    this->OrderID=id;
}
