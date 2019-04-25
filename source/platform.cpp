#include "platform.h"
#include"hotelmanagerlist.h"
#include"hotelmanager.h"
#include"mydatabase.h"
#include"mainwindow.h"
#include"node.h"
#include"linkedlist.h"
#include<QStringLiteral>
#include<QString>
#include"hotellist.h"
#include"roomlist.h"

extern hotelmanagerlist L2;
extern customerlist L1;
extern hotellist L3;
extern roomlist L4;

Node<Holtel> * platform::gethotelinfo(QString hotelname)
{
    Node<Holtel> *p = L3.front;
    for(int i = 0;i<L3.size;i++)
    {
        if(p->data.getHotelname() == hotelname)
        {
            return p;
        }
        p = p->nextNode();
    }

    return nullptr;
}

Node<Room>* platform::getroominfo(QString roomho, QString type)
{
    Node<Room> *p = L4.front;
    for(int i = 0;i<L4.size;i++)
    {
        if(p->data.getRoomHol() == roomho&&p->data.getRoomType() == type)
        {
            return p;
        }
        p = p->nextNode();
    }

    return nullptr;
}
