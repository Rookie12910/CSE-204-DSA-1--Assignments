#include<iostream>
#include"MyStack.h"
#include"ArrayList.h"
using namespace std;

template <class T>
class ArrayStack: public MyStack<T>
{
private:

    ArrayList<T> *astack;
public:
    ArrayStack (int il);
    ArrayStack (ArrayStack<T> &as, int il);
    ~ArrayStack();
    void clear();
    void push(T data);
    T pop();
    int length();
    T topValue();
    void show();
    template <class E>
    friend ostream &operator  <<(ostream &os, ArrayStack<E> &Stack);
};

template<class T>
ArrayStack<T>::ArrayStack(int il)
{
    astack = new ArrayList<T>(il);
}

template<class T>
ArrayStack<T>::ArrayStack(ArrayStack<T> &as,int il)
{
    astack = new ArrayList<T>(il);
    as.astack->setToBegin();
    for(int i =0;i<as.length();i++)
    {
        this->push(as.astack->getValue());
        as.astack->next();
    }
}

template<class T>
ArrayStack<T>::~ArrayStack()
{
    clear();
}

template <class T>
void ArrayStack<T>::clear()
{
    astack->clear();
}
template <class T>
void ArrayStack<T>::push(T data)
{
    astack->pushBack(data);
}

template <class T>
T ArrayStack<T>::pop()
{
    if(length()>0)
    {
    astack->setToEnd();
    T temp;
    temp = astack->erase();
    return temp;
    }
   //else
    //return -1;
}

template <class T>
int ArrayStack<T>::length()
{
    return astack->size();
}

template <class T>
T ArrayStack<T>::topValue()
{
   astack->setToEnd();
   return astack->getValue();
}

template <class T>
void ArrayStack<T>::show()
{
    cout<<*astack<<endl;
}

template <class T>
ostream &operator <<(ostream &os, ArrayStack<T> &Stack)
{
    int currentPos = Stack.astack->currPos();
    Stack.astack->setToBegin();
    os<<"< ";
    for(int i = 0; i<Stack.astack->size(); i++)
    {
        if(Stack.astack->size()>0 && i==Stack.astack->size()-1)
        {
            os<<"| ";
        }
        os<<Stack.astack->getValue()<<" ";
        Stack.astack->next();

    }
    os<<">";
    Stack.astack->setToPos(currentPos);
    return os;
}


