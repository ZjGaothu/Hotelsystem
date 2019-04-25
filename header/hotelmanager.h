#ifndef HOTELMANAGER_H
#define HOTELMANAGER_H
#include"abuser.h"
#include<QString>
#include<holtel.h>
#include<QMessageBox>
#include"room.h"

//酒店管理员类
//继承Abuser 的ID与Password
class Hotelmanager:public AbUser
{
public:
    Hotelmanager(){}
    Hotelmanager(QString ID, QString Password);
    ~Hotelmanager(){}

    void setHotelName(QString name);
    QString getHotelName(){return HotelName;} //返回房间所属酒店名
    void setRoom(Room &a,QString RoomType,float price ,float Discou);
private:
    Holtel myHotel;      //房间所属酒店
    QString HotelName;   //房间所属酒店名




};

#endif // HOTELMANAGER_H
