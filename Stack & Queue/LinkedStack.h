#include"MyStack.h"
#include"LinkedList.h"
using namespace std;

template <class T>
class LinkedStack: public MyStack<T>
{
private:

    LinkedList<T> *lstack;
public:
    LinkedStack ();
    LinkedStack (LinkedStack<T> &ls);
    ~LinkedStack();
    void clear();
    void push(T data);
    T pop();
    int length();
    T topValue();
    void show();
    template <class E>
    friend ostream &operator  <<(ostream &os,LinkedStack<E> &Stack);
};

template<class T>
LinkedStack<T>::LinkedStack()
{
    lstack = new LinkedList<T>;

}

template<class T>
LinkedStack<T>::LinkedStack(LinkedStack<T> &ls)
{
    lstack = new LinkedList<T>;
    ls.lstack->setToBegin();
    for(int i =0;i<ls.length();i++)
    {
        this->push(ls.lstack->getValue());
        ls.lstack->next();
    }

}

template<class T>
LinkedStack<T>::~LinkedStack()
{
    clear();

}

template <class T>
void LinkedStack<T>::clear()
{
    lstack->clear();
}
template <class T>
void LinkedStack<T>::push(T data)
{
    lstack->pushBack(data);
}

template <class T>
T LinkedStack<T>::pop()
{
    if(length()>0)
    {
    lstack->setToEnd();
    T temp;
    temp = lstack->erase();
    return temp;
    }
   //else
    //return -1;
}

template <class T>
int LinkedStack<T>::length()
{
    return lstack->size();
}

template <class T>
T LinkedStack<T>::topValue()
{
   lstack->setToEnd();
   return lstack->getValue();
}

template <class T>
void LinkedStack<T>::show()
{
   cout<<*lstack<<endl;
}

template <class T>
ostream &operator <<(ostream &os,LinkedStack<T> &Stack)
{
    Node<T> *temp = Stack.lstack->head->next;
    int currentPos = Stack.lstack->currPos();
    os<<"< ";
    for(int i = 0; i<Stack.lstack->size(); i++)
    {
        if(Stack.lstack->size()>0 && i==Stack.lstack->size()-1)
        {
            os<<"| ";
        }
        os<<temp->data<<" ";
        temp = temp->next;
    }
    os<<">";
    return os;
}



