#ifndef ROOMLIST_H
#define ROOMLIST_H
#include"linkedlist.h"
#include"node.h"
#include"room.h"

//房间类链表
//存储房间的数据
class roomlist:public LinkedList<Room>
{
public:
    roomlist(){}
    void sortbyprice();                           //按照价格排序
    roomlist searchbytype(QString roomtype);      //按照房间类型搜索
    roomlist searchbyhotel(QString hotelname);    //按照酒店名搜索
    roomlist searchbypermitted();                 //按照酒店是否通过审核搜索
};

#endif // ROOMLIST_H
