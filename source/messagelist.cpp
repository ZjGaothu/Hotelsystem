#include "messagelist.h"
#include"message.h"
#include<QString>
#include"linkedlist.h"
#include"node.h"

messagelist messagelist::searchbysendID(QString id)  //按照发送者ID查找消息
{
    Node<Message> *p = front;
    messagelist right;
    while(p != nullptr)     //遍历消息链表
    {
        if(p->data.getsendID() == id)
        {
            right.insertRear(p->data);
        }
        p = p->nextNode();
    }
    return right;
}

messagelist messagelist::searchbyreceiveID(QString id) //按照接受者ID查找消息
{
    Node<Message> *p = front;
    messagelist right;
    while(p != nullptr)     //遍历消息链表
    {
        if(p->data.getreceiveID() == id)
        {
            right.insertRear(p->data);
        }
        p = p->nextNode();
    }
    return right;
}
