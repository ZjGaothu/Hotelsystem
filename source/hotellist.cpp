#include "hotellist.h"
#include"node.h"
#include"linkedlist.h"
#include<QString>

void hotellist::sortbyscore()  //按照评分排序，改变链表内节点的顺序
{
    Node<Holtel> *p = front;
    int n = size;
    for(int i = 0;i<n;i++)  //冒泡排序
    {
        p = front;
        for(int j = 0;j<n-1;j++)
        {
            if(p->data.getscore()<p->nextNode()->data.getscore())
            {
                Holtel hol;
                hol = p->data;
                p->data = p->nextNode()->data;
                p->nextNode()->data = hol;
            }
            p = p->nextNode();
        }
    }
}

hotellist hotellist::searchbyplace(QString place)  //按照地点找出所有酒店
{
    hotellist right;
    Node<Holtel> *p = front;
    while (p != nullptr)        //遍历查找
    {
        if(p->data.getHotelplace() == place)
        {
            right.insertRear(p->data);
        }
        p = p->nextNode();
    }
    return right;            //返回新链表，即符合查找的结点组成的链表
}

//找到通过审核的所有酒店
hotellist hotellist::searchbypermitted()
{
    hotellist right;
    Node<Holtel> *p = front;
    while (p != nullptr)
    {
        if(p->data.getpermitted() == true)
        {
            right.insertRear(p->data);
        }
        p = p->nextNode();
    }
    return right;
}

//找到未通过审核的酒店
hotellist hotellist::searchbynopermitted()
{
    hotellist right;
    Node<Holtel> *p = front;
    while (p != nullptr)
    {
        if(p->data.getpermitted() == false)
        {
            right.insertRear(p->data);
        }
        p = p->nextNode();
    }
    return right;
}

