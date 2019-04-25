#ifndef MESSAGELIST_H
#define MESSAGELIST_H
#include"linkedlist.h"
#include"node.h"
#include"message.h"

//消息类链表

class messagelist: public LinkedList<Message>
{
public:
    messagelist(){}
    messagelist searchbysendID(QString id);  //返回发送者用户名所发送消息链表
    messagelist searchbyreceiveID(QString id); //返回接受者用户名所接受消息链表

};

#endif // MESSAGELIST_H
