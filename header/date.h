#ifndef DATE_H
#define DATE_H
// 日期类
// 计算时长 存储日期数据


class Date
{
private:
    int year; //私有数据 年
    int month; //月
    int day; //日
public:
    Date(){}
    Date(int year1, int month1, int day1);
    Date(const Date &a);
    bool IsLeapYear(int y) //判断是否为闰年
    {
        return  ((0 == y % 4 && 0 != y % 100) || (0 == y % 400));
    }
    int daysOfMonth(int y,int m); //返回某月的天数
    int daysOfDate();       //返回当前日期距离公元0年的天数
    int distance(Date &d)  //计算日期间的天数
    {
        return (this->daysOfDate()-d.daysOfDate());
    }
    int getyear(){return year;}
    int getmonth(){return month;}
    int getday(){return day;}
};

#endif // DATE_H
