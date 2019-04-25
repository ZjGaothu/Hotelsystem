#ifndef ORDERLIST_H
#define ORDERLIST_H
#include"linkedlist.h"
#include"node.h"
#include"order.h"

//订单类链表
//用于查找订单
class orderlist:public LinkedList<Order>
{
public:
    orderlist(){}
    orderlist searchbycusID(QString id);  //按照顾客用户名查找订单
    orderlist searchbyispaid();           //查找已支付订单
    orderlist searchbynopaid();           //查找未支付订单
    orderlist searchbyhotel(QString ho);  //按照酒店名查找订单
};

#endif // ORDERLIST_H
