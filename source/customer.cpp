#include "customer.h"
#include<QString>

Customer::Customer(QString ID1, QString Password1, QString IDNumber1,float treasure1)
{
    this->setID(ID1);
    this->setPassword(Password1);
    this->settreasure(treasure1);
    IDNumber = IDNumber1;

}

void Customer::setIDNumber(QString id)
{
    IDNumber = id;
}

void Customer::settreasure(float trea)
{
    treasure = trea;
}


//判断用户是否可以支付费用，如果可以，支付其费用
bool Customer::Paymoney(float money)
{
    if(treasure>=money)
    {
        treasure-=money;
        return true;
    }
    else
        return false;
}
//用户余额充值
void Customer::recharge(float money)
{
    treasure += money;
}
