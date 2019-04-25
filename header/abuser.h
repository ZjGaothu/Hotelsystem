#ifndef ABUSER_H
#define ABUSER_H
#include<QString>
//***************************************
//【类名】 AbUser
//【功能】 用户名和密码的获取，用于Customer和Hotelmanager的继承
//***************************************

class AbUser
{
private:
    QString ID;
    QString Password;
public:
    AbUser(){}
    AbUser(QString ID1,QString Password1):ID(ID1),Password(Password1){}
    ~AbUser() {}
    QString getID() { return ID; }
    QString getPassword() { return Password; }
    void setID(QString ID);
    void setPassword(QString Password);
    void changePassword(QString Password);

};

#endif // ABUSER_H
