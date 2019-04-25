#include "message.h"
#include<QString>


void Message::setsendID(QString id)
{
    this->sendID = id;
}

void Message::setreceiveID(QString id)  //初始化接受者ID
{
    this->receiveID = id;
}

void Message::setmessage(QString message1) //初始化消息
{
    this->message = message1;
}
