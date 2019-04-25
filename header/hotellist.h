#ifndef HOTELLIST_H
#define HOTELLIST_H
#include<QString>
#include"linkedlist.h"
#include"node.h"
#include"holtel.h"

//酒店类链表

class hotellist:public LinkedList<Holtel>
{
public:
    hotellist(){}
    void sortbyscore();
    hotellist searchbyplace(QString place);
    hotellist searchbypermitted();
    hotellist searchbynopermitted();
};

#endif // HOTELLIST_H
