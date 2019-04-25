#include "roomlist.h"
#include"node.h"
#include"linkedlist.h"
#include"holtel.h"
#include"hotellist.h"
#include<QString>

extern hotellist L3;

void roomlist::sortbyprice()  //按照价格排序
{
    Node<Room> *p = front;
    int n = size;
    for(int i = 1;i<n;i++)
    {
        p = front;
        for(int j = 0;j<n-i;j++)
        {
            if(p->data.getRoomprice()<p->nextNode()->data.getRoomprice())
            {
                Room roo;
                roo = p->data;
                p->data = p->nextNode()->data;
                p->nextNode()->data=roo;
            }
            p = p->nextNode();
        }
    }

}


roomlist roomlist::searchbytype(QString roomtype)  //找出该类型的房间
{
    roomlist right;
    Node<Room> *p = front;
    while (p != nullptr)
    {
        if(p->data.getRoomType() == roomtype)
        {
            right.insertRear(p->data);
        }
        p = p->nextNode();
    }
    return right;
}

roomlist roomlist::searchbyhotel(QString hotelname) //找出该酒店的所有房间
{
    roomlist right;
    Node<Room> *p = front;
    while (p != nullptr)
    {
        if(p->data.getRoomHol() == hotelname)
        {
            right.insertRear(p->data);
        }
        p = p->nextNode();
    }
    return right;
}

roomlist roomlist::searchbypermitted()     //找出所属酒店通过审核的所有订单
{
    roomlist right;
    Node<Room> *p = front;
    while(p != nullptr)
    {
        Node<Holtel> *p1 = L3.front;
        while(p1 != nullptr)
        {
            if(p1->data.getHotelname() == p->data.getRoomHol())
            {
                if(p1->data.getpermitted())
                {
                    right.insertRear(p->data);
                }
            }
            p1 = p1->nextNode();
        }
        p = p->nextNode();
    }
    return right;
}
