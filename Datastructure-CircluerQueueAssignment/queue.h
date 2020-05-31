#ifndef STATICQUEUES_H_
#define STATICQUEUES_H_
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
const int maxQueue = 200;
template <class QueueElementType>
class StaticQueue {
public:
    StaticQueue();
    bool enqueue(const QueueElementType& item);
    bool dequeue();
    int nextPosition(int p);
    void order();
    void normalize(QueueElementType item);
    void nonNormalize(QueueElementType item);
    bool found(QueueElementType item);
    int fronty();
    void print();

private:
    int front_index; // indicates front
    int rear_index; // indicates rear
    QueueElementType queueArray[maxQueue];

};

template <class QueueElementType>
StaticQueue<QueueElementType>::StaticQueue()
{
    front_index = 0;
    rear_index = 0;
}

template <class QueueElementType>
bool StaticQueue<QueueElementType>::enqueue(const QueueElementType& item)
{
   if (nextPosition(rear_index) == front_index) {
        return false; // Queue is Full
    }
    else {
        queueArray[rear_index] = item;
        rear_index = nextPosition(rear_index);
        return true;
    }
}

template <class QueueElementType>
bool StaticQueue<QueueElementType>::dequeue()
{
    if (rear_index == front_index) {
        return false; // Queue is Empty
    }
    else {
        front_index = nextPosition(front_index);
        return true;
    }
}

template <class QueueElementType>
int StaticQueue<QueueElementType>::nextPosition(int p)
{
    return ((p + 1) % maxQueue);
}

template <class QueueElementType>
void StaticQueue<QueueElementType>::order()
{
    int tem;
    for(int i=0;i<rear_index-1;i++)
        for(int j=0;j<rear_index-1;j++)
    {
        if(queueArray[j]>queueArray[j+1])
        {
            tem=queueArray[j];
            queueArray[j]=queueArray[j+1];
            queueArray[j+1]=tem;

        }
    }

}

template <class QueueElementType>
void StaticQueue<QueueElementType>::normalize(QueueElementType item)
{
    int var =0;
    for(int i=front_index;i<rear_index;i++)
    {
        if(queueArray[i]==item)
        {
          queueArray[i] = queueArray[i]+((item+1)*var);
          var++;

        }
        else{
            queueArray[i]=queueArray[i]+((item+1)*var);
        }
    }
}

template <class QueueElementType>
void StaticQueue<QueueElementType>::nonNormalize(QueueElementType item )
{
    for(int i=front_index;i<rear_index;i++)
        queueArray[i]=queueArray[i]%(item+1);
}

template <class QueueElementType>
bool StaticQueue<QueueElementType>::found(QueueElementType item )
{
    bool yes=false;
    for(int i=front_index;i<rear_index;i++){
        if(item==queueArray[i])
            yes=true;
    }
    if(yes)
        return true;
    else
        return false;
}

template <class QueueElementType>
void StaticQueue<QueueElementType>::print()
{
 int i;
    for( i = front_index; i < rear_index; i++)
    {
        cout<< queueArray[i] << " ";
    }
}

template <class QueueElementType>
int StaticQueue<QueueElementType>::fronty()
{
    if (rear_index == front_index) {
        return 0;// Queue is Empty
    }
    else {
      return queueArray[front_index];
    }
}
#endif /* STATICQUEUES_H_ */
