#ifndef PLATFORM_H
#define PLATFORM_H
#include"customer.h"
#include"holtel.h"
#include"room.h"


class platform
{
public:
    platform();
    Node<Holtel> *gethotelinfo(QString hotelname);             //返回酒店信息
    Node<Room> *getroominfo(QString roomho,QString type);      //返回房间信息

};

#endif // PLATFORM_H
