#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include"node.h"
//***********************************************
//【类名】  LinkedList（链表类）
//【功能】  插入结点、删除结点、用于之后Customer、Hotelmanager类的继承创建链表
//***********************************************
template<class T>
class LinkedList
{
private:
    Node<T>* newNode(const T&item, Node<T>*ptrNext =nullptr);//生成新结点
    void freeNode(Node<T> *p);  //释放结点
public:
    int size;
    int position;
    Node<T> *prevPtr, *currPtr; //记录表当前遍历位置的指针，由插入与删除操作更新
    Node<T> *front, *rear;//表头和表尾的指针
    LinkedList();//构造
    LinkedList(const LinkedList<T> &L); //复制构造
    ~LinkedList(); //析构
    LinkedList<T> &operator=(const LinkedList<T> &L);//重载运算符

    int getSize()const;  //获取链表元素个数
    bool isEmpty() const; //判断链表是否为空
    void copy(const LinkedList<T>&L); //将L复制到当前表
    void reset(int pos = 0); //初始化游标
    void next(); //游标返回到下一结点
    bool endOfList() const;
    int currentPosition(void) const; //返回到当前的position

    void insertFront(const T&item); //在表头加入结点
    void insertRear(const T &item); //在表尾加入结点
    void insertAt(const T &item);
    void insertAfter(const T&item); //在当前结点之后插入结点

    void deleteFront();  //删除表头结点
    void deleteCurrent(); //删除当前结点

    T& data();  //返回数据引用
    const T& data() const; //返回数据常引用

    void clear(); //清空链表，释放内存
};

template <class T>
LinkedList<T>::LinkedList()
{
    front = nullptr;
    rear = nullptr;
    prevPtr = nullptr;
    currPtr = nullptr;
    size = 0;
    position = -1;
}

template <class T>
LinkedList<T>::LinkedList(const LinkedList<T> &L)
{
    copy(L);
}

template <class T>
LinkedList<T>::~LinkedList()
{
    clear();
}


template <class T>
LinkedList<T> &LinkedList<T>::operator= (const LinkedList<T> &L)
{
    copy(L);
}


template <class T>
int LinkedList<T>::getSize() const
{
    return size;
}


template <class T>
bool LinkedList<T>::isEmpty()const
{
    if (front == nullptr)
    {
        return true;
    }
    else
        return false;
}


template<class T>
void LinkedList<T>::reset(int pos /*= 0*/) {
    int startPos;
    if (front == nullptr)
        return;
    if (pos == 0)
    {
        prevPtr = nullptr;
        currPtr = front;
        position = 0;
    }
    else {
        currPtr = front->nextNode();
        prevPtr = front;
        startPos = 1;
        for (position = startPos; position != pos; position++)
        {
            prevPtr = currPtr;
            currPtr = currPtr->nextNode();
        }
    }
}


template <class T>
void LinkedList<T>::next()
{
    prevPtr = currPtr;
    currPtr = currPtr->nextNode();
    position++;
}


template <class T>
bool LinkedList<T>::endOfList()const
{
    if (currPtr->nextNode())
        return false;
    else
        return true;
}


template <class T>
int LinkedList<T>::currentPosition(void) const
{
    return position;
}


template <class T>
void LinkedList<T>::insertFront(const T&item)
{
    Node<T>*p = newNode(item,front);
    front = p;
    size++;
    position++;
}

template<class T>
void LinkedList<T>::insertRear(const T &item) {
    Node<T>*node1;
    prevPtr = rear;
    node1 = newNode(item);
    if (rear == nullptr)
        front = rear = node1;
    else {
        rear->insertAfter(node1);
        rear = node1;
    }
    currPtr = rear;
    position = size;
    size++;
}



template <class T>
void LinkedList<T>::insertAt(const T&item)
{
    Node<T>*node1;
        if (prevPtr == nullptr)
        {
            node1 = newNode(item, front);//新节点的next指向原来的头
            front = node1;
        }
        else {
            node1 = newNode(item);//末尾指空
            prevPtr->insertAfter(node1);//插到上一指针之后，转化
        }
        if (prevPtr == rear) {
            rear = node1;
            position = size;
        }
        currPtr = node1;
        size++;
}


template <class T>
void LinkedList<T>::insertAfter(const T &item)
{
    Node<T> *p = newNode(item);
    if (front = nullptr)
    {
        currPtr = front = rear = p;
        position = 0;
    }
    else
    {
        if(currPtr==nullptr)
        {
            currPtr = prevPtr;
            currPtr->insertAfter(p);

        }
        if (currPtr = rear)
        {
            rear = p;
            position = size;
        }
        else
        {
            position++;
            prevPtr = currPtr;
            currPtr = p;
        }
    }
    size++;
}


template <class T>
void LinkedList<T>::deleteFront()
{
    Node<T>*p = front->nextNode();
    delete front;
    front = p;
    size--;
    if (position)
        position--;
}


template <class T>
void LinkedList<T>::deleteCurrent()
{
    Node<T>*p;
        if (prevPtr == nullptr)
        {
            p = front;
            front = front->nextNode();
        }
        else  p = prevPtr->deleteAfter();
        if (p == rear) {
            rear = prevPtr;
            position--;
        }
        currPtr = p->nextNode();
        freeNode(p);
        size--;
}


template <class T>
T& LinkedList<T>::data()
{
    return currPtr->data;
}



template <class T>
const T& LinkedList<T>::data() const
{
    return currPtr->data;
}


template <class T>
void LinkedList<T>::clear()
{
    reset();
    for (int i = 0; i < size - 1; i++)
    {
        next();
        delete prevPtr;
    }
    delete currPtr;
    front = rear = prevPtr = currPtr = nullptr;
    size = position = 0;
}


template<class T>
void LinkedList<T>::copy(const LinkedList<T>&L)
{
    Node<T>*p = L.front;
    int pos;
    while (p != nullptr)
    {
        insertRear(p->data);
        p = p->nextNode();
    }
    if (position == -1)  //如果原先是空函数
        return;
    prevPtr = nullptr;
    currPtr = front;
    for (pos = 0; pos != position; pos++)
    {
        prevPtr = currPtr;
        currPtr = currPtr->nextNode();
    }
}

template <class T>
void LinkedList<T>::freeNode(Node<T> *p)
{
    delete p; //直接删除
}

template <class T>
Node<T>* LinkedList<T>::newNode(const T &item, Node<T>*ptrNext)
{
    Node<T> *p;
    p = new Node<T>(item, ptrNext);
    return p;
}

#endif // LINKEDLIST_H
