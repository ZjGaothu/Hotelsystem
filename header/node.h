#ifndef NODE_H
#define NODE_H

//结点类
template<class T>
class Node
{
private:
    Node<T>* next; //后继结点
public:
    T data;       //数据

    Node(const T&data, Node<T> *next = 0);
    void insertAfter(Node<T>*p);
    Node<T>*deleteAfter();
    Node<T>*nextNode();
    const Node<T> *nextNode() const;
};

template<class T>
Node<T>::Node(const T&data, Node<T>*next/*=0*/) :data(data), next(next) {}

template<class T>
Node<T>*Node<T>::nextNode()    //返回后继结点
{
    return next;
}

template<class T>
const Node<T>*Node<T>::nextNode() const
{
    return next;
}

template<class T>
void Node<T>::insertAfter(Node<T> *p)  //在结点后插入结点
{
    p->next = next;
    next = p;
}

template<class T>
Node<T>* Node<T>::deleteAfter()      //结点后删除结点
{
    Node<T>*tempPtr = next;
    if (next == 0)
        return 0;
    next = tempPtr->next;
    return tempPtr;
}

#endif // NODE_H
