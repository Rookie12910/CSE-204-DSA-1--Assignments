#include<iostream>
#include "MyList.h"
using namespace std;
template <class T>
class ArrayList : public MyList<T>
{
private:
    int curr_Pos;
    T *array;
    int arrlength;//capacity
    int listsize;//number of elements
    void resize();//helper function
    bool need_to_resize();//helper function
public:
    ArrayList(int il);
    ArrayList(ArrayList<T> &Al,int capacity);
    ~ArrayList();
    int size();
    void push( T data);
    void pushBack (T data);
    T erase();
    void setToBegin ();
    void setToEnd ();
    void prev();
    void next();
    int currPos ();
    void setToPos (int pos);
    T getValue ();
    int find (T data);
    void clear();
    template <class E>
    friend ostream &operator  <<(ostream &os, ArrayList<E> &llist);

};

template <class T>
ArrayList<T>::ArrayList( int capacity)
{
    array = new T[capacity];
    arrlength = capacity;
    listsize = 0;
    curr_Pos = 0;
}

template <class T>
ArrayList<T>::ArrayList( ArrayList<T> &Al, int capacity)
{
    array = new T[capacity];
    arrlength = capacity;
    listsize = 0;
    curr_Pos = 0;
    int currentPos = Al.currPos();
    Al.setToBegin();
    if(Al.size()>0)
    {
        for(int i =0; i<Al.size(); i++)
        {
            this->pushBack(Al.getValue());
            Al.next();
        }
        Al.setToPos(currentPos);
    }

}

template <class T>
ArrayList<T>::~ArrayList()
{
    delete[] array;
}

template <class T>
bool ArrayList<T>::need_to_resize()
{
    return (listsize >= arrlength || listsize<(arrlength/2));
}


template <class T>
void ArrayList<T>::resize()
{
    if(listsize>=arrlength)
    {
        T *temp = new T[arrlength*2];
        for(int i =0; i<listsize; i++)
        {
            temp[i]=array[i];
        }
        delete []array;
        array = temp;
        arrlength*=2;
    }
    else if(listsize<(arrlength/2))
    {
        T *temp = new T[arrlength/2];
        for(int i =0; i<listsize; i++)
        {
            temp[i]=array[i];
        }
        delete array;
        array = temp;
        arrlength=arrlength/2;
    }

}

template <class T>
int ArrayList<T>::size() //O(1)
{
    return listsize;
}

template <class T>
void ArrayList<T>::push(T data)//O(n)
{
    if(need_to_resize())
        resize();
    for(int i = listsize; i> curr_Pos; i--)
    {
        array[i] = array[i-1];
    }
    array[curr_Pos] = data;
    listsize++;

}

template <class T>
void ArrayList<T>::pushBack(T data)//O(n)
{
    if(need_to_resize())
        resize();
    array[listsize] = data;
    listsize++;
}

template <class T>
T ArrayList<T>::erase()//O(n)
{
    if(listsize>0 && curr_Pos<=(listsize-1))
    {
        T temp = array[curr_Pos];
        for(int i = curr_Pos; i<(listsize-1); i++)
        {
            array[i] = array[i+1];
        }
        listsize--;
        if(curr_Pos==listsize)
        {
            curr_Pos--;
        }
        if(need_to_resize())
            resize();
        return temp;
    }

}

template <class T>
void ArrayList<T>::setToBegin()//O(1)
{
    curr_Pos = 0;
}

template <class T>
void ArrayList<T>::setToEnd()//O(1)
{
    curr_Pos = listsize-1;
}

template <class T>
void ArrayList<T>::prev()//O(1)
{
    if(curr_Pos!=0)
        curr_Pos--;
}

template <class T>
void ArrayList<T>::next()//O(1)
{
    if(curr_Pos!=listsize-1)
        curr_Pos++;
}

template <class T>
int ArrayList<T>::currPos()//O(1)
{
    return curr_Pos;
}

template <class T>
void ArrayList<T>::setToPos( int pos)//O(1)
{
    if(pos>=0 && pos<=this->size())
    {
        curr_Pos = pos;
    }
}

template <class T>
T ArrayList<T>::getValue()//O(1)
{
    if(listsize>0 && curr_Pos<=(listsize-1))
    {
        return array[curr_Pos];
    }

}

template <class T>
int ArrayList<T>::find(T data)//O(n)
{
    for(int i =0; i<listsize; i++)
    {
        if(array[i]==data)
            return i;
    }
    return -1;
}

template <class T>
void ArrayList<T>::clear()//O(1)
{
    this->arrlength = arrlength;
    this->listsize = 0;
    this->curr_Pos = 0;
    delete []array;
    this->array = new T[this->arrlength];
}

template <class T>
ostream &operator <<(ostream &os, ArrayList<T> &alist)
{
    int currentPos = alist.curr_Pos;
    alist.setToBegin();
    os<<"<";
    for(int i = 0; i<alist.size(); i++)
    {
        if(i==currentPos) os<<"|";
        os<<alist.getValue()<<" ";
        alist.next();
    }
    os<<">";
    alist.setToPos(currentPos);
    return os;
}

