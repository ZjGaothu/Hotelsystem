#ifndef MESSAGE_H
#define MESSAGE_H
#include<QString>


//消息类
class Message
{
public:
    Message(){}                               //构造函数

    void setsendID(QString id);               //初始化发送者用户名
    void setreceiveID(QString id);            //初始化接受者用户名
    void setmessage(QString message1);        //初始化发送的消息
    QString getsendID(){return sendID;}       //获取发送者用户名
    QString getreceiveID(){return receiveID;} //获取接受者用户名
    QString getmessage(){return message;}     //获取消息
private:
    QString sendID;
    QString receiveID;
    QString message;

};

#endif // MESSAGE_H
