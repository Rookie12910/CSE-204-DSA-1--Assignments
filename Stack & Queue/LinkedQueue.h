#include"MyQueue.h"
#include"LinkedList.h"
using namespace std;

template <class T>
class LinkedQueue: public MyQueue<T>
{
private:

    LinkedList<T> *lqueue;
public:
    LinkedQueue ();
    LinkedQueue (LinkedQueue<T> &lq);
    ~LinkedQueue();
    void clear();
    void enqueue(T data);
    T dequeue();
    int length();
    T frontValue();
    T rearValue();
    T leaveQueue();
    void show();
    template <class E>
    friend ostream &operator  <<(ostream &os,LinkedQueue<E> &Queue);
};

template<class T>
LinkedQueue<T>::LinkedQueue()
{
    lqueue = new LinkedList<T>;
}

template<class T>
LinkedQueue<T>::LinkedQueue(LinkedQueue<T> &lq)
{
    lqueue = new LinkedList<T>;
    lq.lqueue->setToBegin();
    for(int i =0;i<lq.length();i++)
    {
        this->enqueue(lq.lqueue->getValue());
        lq.lqueue->next();
    }
}

template<class T>
LinkedQueue<T>::~LinkedQueue()
{
    clear();
}


template <class T>
void LinkedQueue<T>::clear()
{
    lqueue->clear();
}
template <class T>
void LinkedQueue<T>::enqueue(T data)
{
    lqueue->pushBack(data);
}

template <class T>
T LinkedQueue<T>::dequeue()
{
   if(length()>0)
   {
   lqueue->setToBegin();
   T temp;
   temp = lqueue->erase();
   return temp;
   }
   //else
    //return -1;
}

template <class T>
int LinkedQueue<T>::length()
{
    return lqueue->size();
}

template <class T>
T LinkedQueue<T>::frontValue()
{
   lqueue->setToBegin();
   return lqueue->getValue();
}

template <class T>
T LinkedQueue<T>::rearValue()
{
   lqueue->setToEnd();
   return lqueue->getValue();
}

template <class T>
T LinkedQueue<T>::leaveQueue()
{
    if(length()>0)
    {
    lqueue->setToEnd();
    T temp;
    temp = lqueue->erase();
    return temp;
    }
   //else
    //return -1;
}

template <class T>
void LinkedQueue<T>::show()
{
   cout<<*lqueue<<endl;
}

template <class T>
ostream &operator <<(ostream &os,LinkedQueue<T> &Queue)
{
    Node<T> *temp = Queue.lqueue->head->next;
    int currentPos = Queue.lqueue->currPos();
    os<<"<";
    for(int i = 0; i<Queue.lqueue->size(); i++)
    {
        if(Queue.lqueue->size()>0 && i == 0)
        {
          os<<" | ";
        }
        os<<temp->data<<" ";
        temp = temp->next;
    }
    os<<">";
    return os;
}




