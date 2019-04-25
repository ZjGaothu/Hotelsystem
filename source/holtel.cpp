#include "holtel.h"
#include<QString>

void Holtel::setpermitted(bool Ispermitted)
{
    this->ispermitted = Ispermitted;
}
void Holtel::setscore(float score)
{
    this->score = score;
}

void Holtel::setHotelname(QString name)
{
    this->Hotelname = name;
}

void Holtel::setHotelplace(QString place)
{
    this->Hotelplace = place;
}

void Holtel::setHoteltel(QString tel)
{
    this->Hoteltel = tel;
}
//构造
Holtel::Holtel(QString Hotelname1, QString Hotelplace1, QString Hoteltel1)
{
    Hotelname = Hotelname1;
    Hotelplace = Hotelplace1;
    Hoteltel = Hoteltel1;
}

void Holtel::setnumofscore(int num)
{
    this->Numofscore = num;
}
