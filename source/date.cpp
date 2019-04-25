#include "date.h"

Date::Date(const Date &a)
{
    this->year=a.year;
    this->month=a.month;
    this->day=a.day;
}

Date::Date(int year1, int month1, int day1)
{
    year = year1;
    month = month1;
    day = day1;
}

int Date::daysOfMonth(int y,int m)
{
    int d[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };  //初始化数组
    if (m != 2)return d[m - 1];
    else return(28 + IsLeapYear(y));                      //二月是通过是否是闰年判别
}

int Date::daysOfDate()
{
    int d = day;
    for (int y = 1; y < year; y++)                       //从公元零年累加
    {
        d+= 365 + IsLeapYear(y);
    }
    for (int z = 1; z < month; z++)                      //当前年从一月累加
    {
        d += daysOfMonth(year, z);
    }
    return d;
}

