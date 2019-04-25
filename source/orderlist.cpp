#include "orderlist.h"
#include"node.h"
#include"linkedlist.h"
#include<QString>
extern orderlist L5;

orderlist orderlist::searchbycusID(QString id) //按照顾客的id找出其所有订单
{
    orderlist right;
    Node<Order> *p = L5.front;
    while(p != nullptr)
    {
        if(p->data.getcustomerid() == id)
        {
            right.insertRear(p->data);
        }
        p = p->nextNode();
    }
    return right;

}

orderlist orderlist::searchbyispaid()     //遍历找出已付款的所有订单
{
    orderlist right;
    Node<Order> *p = this->front;
    while(p != nullptr)                   //从当前表头开始遍历
    {
        if(p->data.getispaid())
        {
            right.insertRear(p->data);
        }
        p = p->nextNode();
    }
    return right;
}

orderlist orderlist::searchbynopaid()     //遍历找出未付款的所有订单
{
    orderlist right;
    Node<Order> *p = this->front;
    while(p != nullptr)
    {
        if(p->data.getispaid() == false)
        {
            right.insertRear(p->data);
        }
        p = p->nextNode();
    }
    return right;
}

orderlist orderlist::searchbyhotel(QString ho)   //遍历找出某酒店的所有订单
{
    orderlist right;
    Node<Order> *p = L5.front;
    while(p != nullptr)
    {
        if(p->data.getHotelname() == ho)
        {
            right.insertRear(p->data);
        }
        p = p->nextNode();
    }
    return right;
}
