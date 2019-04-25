#include "hotelmanager.h"
#include<QString>
#include"room.h"

Hotelmanager::Hotelmanager(QString ID1, QString Password1)  //构造
{
    this->setID(ID1);
    this->setPassword(Password1);
}

//初始化酒店名
void Hotelmanager::setHotelName(QString name)
{
    this->HotelName = name;
}

//创建并初始化房间
void Hotelmanager::setRoom(Room &a, QString RoomType, float price, float Discou)
{
       a.setRoom(RoomType,price,Discou);
}

