#ifndef HOTELMANAGERLIST_H
#define HOTELMANAGERLIST_H
#include"linkedlist.h"
#include<QString>
#include"node.h"
#include"hotelmanager.h"

//酒店管理员类链表
class hotelmanagerlist:public LinkedList <Hotelmanager>
{
public:
    hotelmanagerlist(){}

};

#endif // HOTELMANAGERLIST_H
