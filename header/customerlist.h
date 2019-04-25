#ifndef CUSTOMERLIST_H
#define CUSTOMERLIST_H
#include"linkedlist.h"
#include<QString>
#include"customer.h"
#include"node.h"
class Customer;
//**************************************
// 【类名】 customerlist （顾客类链表）
// 【功能】 从Linkedlist继承
//**************************************

class customerlist: public LinkedList<Customer>
{
public:
    customerlist(){}

};
#endif // CUSTOMERLIST_H
