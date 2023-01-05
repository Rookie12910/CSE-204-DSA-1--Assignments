#include"MyQueue.h"
#include"ArrayList.h"
using namespace std;

template <class T>
class ArrayQueue : public MyQueue<T>
{
private:
    ArrayList<T> *aqueue;
public:
    ArrayQueue (int il);
    ArrayQueue (ArrayQueue<T> &aq,int il);
    ~ArrayQueue();
    void clear();
    void enqueue(T data);
    T dequeue();
    int length();
    T frontValue();
    T rearValue();
    T leaveQueue();
    void show();
    template <class E>
    friend ostream &operator  <<(ostream &os, ArrayQueue<E> &Queue);
};

template<class T>
ArrayQueue<T>::ArrayQueue(int il)
{
    aqueue = new ArrayList<T>(il);
}

template<class T>
ArrayQueue<T>::ArrayQueue(ArrayQueue <T> &aq,int il)
{
    aqueue = new ArrayList<T>(il);
    aq.aqueue->setToBegin();
    for(int i =0;i<aq.length();i++)
    {
        this->enqueue(aq.aqueue->getValue());
        aq.aqueue->next();
    }
}

template<class T>
ArrayQueue<T>::~ArrayQueue()
{
    clear();
}

template <class T>
void ArrayQueue<T>::clear()
{
    aqueue->clear();
}
template <class T>
void ArrayQueue<T>::enqueue(T data)
{
    aqueue->pushBack(data);
}

template <class T>
T ArrayQueue<T>::dequeue()
{
   if(length()>0)
   {
   aqueue->setToBegin();
   T temp;
   temp = aqueue->erase();
   return temp;
   }
   //else
    //return -1;
}

template <class T>
int ArrayQueue<T>::length()
{
    return aqueue->size();
}

template <class T>
T ArrayQueue<T>::frontValue()
{
   aqueue->setToBegin();
   return aqueue->getValue();
}

template <class T>
T ArrayQueue<T>::rearValue()
{
   aqueue->setToEnd();
   return aqueue->getValue();
}

template <class T>
T ArrayQueue<T>::leaveQueue()
{
   if(length()>0)
   {
    aqueue->setToEnd();
   T temp;
   temp = aqueue->erase();
   return temp;
   }
   //else
    //return -1;
}

template <class T>
void ArrayQueue<T>::show()
{
   cout<<*aqueue<<endl;
}
template <class T>
ostream &operator <<(ostream &os, ArrayQueue<T> &Queue)
{
    int currentPos = Queue.aqueue->currPos();
    Queue.aqueue->setToBegin();
    os<<"<";
    for(int i = 0; i<Queue.aqueue->size(); i++)
    {
        if(Queue.aqueue->size()>0 && i ==0)
        {
           os<<" | ";
        }
        os<<(Queue.aqueue->getValue())<<" ";
        Queue.aqueue->next();
    }
    os<<">";
    Queue.aqueue->setToPos(currentPos);
    return os;
}



