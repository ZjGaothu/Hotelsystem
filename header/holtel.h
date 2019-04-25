#ifndef HOLTEL_H
#define HOLTEL_H
#include<QString>

class Holtel
    {
    private:
        QString Hotelname;  //酒店名称
        QString Hotelplace;//酒店地址
        QString Hoteltel;//电话
        bool ispermitted; //是否被审核通过
        float score;  //酒店的评分
        int Numofscore; //酒店拥有评分的数量
    public:
        friend class Customer; //友元类
        friend class HotelManager;

        //返回私有数据，调用时可得到私有数据的值
        QString& getHotelname() { return Hotelname; }
        QString& getHotelplace() { return Hotelplace; }
        QString& getHoteltel() { return Hoteltel; }
        float getscore() { return score;}
        int getnumofscore(){return Numofscore;}
        bool getpermitted(){return ispermitted;}

        //设置初始化私有数据
        void setscore(float score);
        void setHotelname(QString name);
        void setHotelplace(QString place);
        void setHoteltel(QString tel);
        void setpermitted(bool Ispermitted);
        void setnumofscore(int num);


        Holtel(){}
        Holtel(QString Hotelname1, QString Hotelplace1, QString Hoteltel1);
        ~Holtel(){}

    };


#endif // HOLTEL_H
