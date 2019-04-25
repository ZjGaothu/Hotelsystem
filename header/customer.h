#ifndef CUSTOMER_H
#define CUSTOMER_H
#include<QString>
#include"abuser.h"
#include"order.h"
#include"holtel.h"
#include"node.h"
#include"linkedlist.h"

//*****************************************
//【类名】 Customer (顾客类）
//【功能】 从AbUser继承 可获取顾客的身份证号、余额、用户名、密码等，并可进行付款
//*****************************************

class Customer:public AbUser
{
private:
    QString IDNumber;//身份证号
    float treasure;//用户余额
public:
    Customer(){}
    Customer(QString ID, QString Password, QString IDNumber,float treasure);
    ~Customer(){}

    void setIDNumber(QString id);
    void settreasure(float trea);

    QString getIDNumber() { return IDNumber; }
    float gettreasure(){return treasure;}
    bool Paymoney(float money);
    void recharge(float money);

};
#endif // CUSTOMER_H
