#ifndef ROOM_H
#define ROOM_H
#include<QString>
//房间类



class Room
{
private:
    QString RoomHol;               //房间所属的酒店
    QString RoomDiscription;       //房间描述
    QString RoomType;              //房间类型

    float Roomprice;               //房间价格
    float Discounts;               //优惠
    int Roomnum;                   //房间量
public:
    Room() {}
    ~Room(){}
    Room(QString RoomType, QString Discription, float price, float Discou = 0);

    void setRoom(QString RoomType,float price, float Discou = 0);
    void setRoomType(QString Type);
    void setRoomHol(QString Hol);
    void setRoomDiscription(QString dis);
    void setRoomnum(int num);
    void setRoomprice(float price);
    void setRoomdiscount(float dis);     //初始化优惠

    QString getRoomHol() {return RoomHol;}
    QString getRoomType() { return RoomType; }
    QString getRoomDiscription(){return RoomDiscription;}
    float getRoomprice() { return Roomprice; }
    float getDiscounts() { return Discounts; }
    int getRoomnum(){return Roomnum;}



};

#endif // ROOM_H
