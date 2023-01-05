#ifndef HeaderL
#define HeaderL

#include <iostream>
#include<fstream>

using namespace std;

template <class T>
class Node
{
public:
    T data;
    Node<T> *next;
    Node()
    {
        next = NULL;
    }
    Node(T data )
    {
        this->data = data;
        next = NULL;
    }
};

template <class T>
class LinkedList
{
public:
    Node<T> *head;
    Node<T> *tail;
    Node<T> *curr_pos;
    int listsize;
    LinkedList();
    LinkedList(LinkedList<T> & Ll);
    ~LinkedList();
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
    friend ostream &operator  <<(ostream &os,LinkedList<E> &llist);
};

template <class T>
LinkedList<T>::LinkedList()
{
    head = tail = curr_pos = new Node <T>;
    listsize = 0;
    setToBegin();
}

template <class T>
LinkedList<T>::LinkedList(LinkedList<T> & Ll)
{
    head = tail = curr_pos = new Node <T>;
    listsize = 0;
    if(Ll.size()>0)
    {
        int currentpos = Ll.currPos();
        Ll.setToBegin();
        for(int i =0; i<Ll.size(); i++)
        {
            this->pushBack(Ll.getValue());
            Ll.next();
        }
        Ll.setToPos(currentpos);
    }
}

template <class T>
LinkedList<T>::~LinkedList()
{
    clear();
}

template <class T>
int LinkedList<T>:: size()//O(1)
{
    return listsize;
}

template <class T>
void LinkedList<T>::push (T data)//O(1)
{
    Node<T> *temp = new Node<T>(data);
    temp->next = curr_pos->next;
    curr_pos->next = temp;
    if(curr_pos==tail)
    {
        tail = curr_pos->next;
    }
    listsize++;
}

template <class T>
void LinkedList<T>::pushBack(T data)//O(1)
{
    Node<T> *temp = new Node<T>(data);
    tail->next = temp;
    tail = temp;
    listsize++;
}

template <class T>
T LinkedList<T>:: erase()//O(n)
{
    if( curr_pos!=NULL && curr_pos->next!=NULL)
    {
    T temp_data = curr_pos->next->data;
    Node<T> *tobeDeleted = curr_pos->next;
    curr_pos->next = curr_pos->next->next;
    if(curr_pos->next==NULL)
    {
        tail = curr_pos;
    }
    delete tobeDeleted;
    listsize--;
    return temp_data;
    }
    //else
        //return -1;

}

template <class T>
void LinkedList<T>::setToBegin()//O(1)
{
    curr_pos = head;
}

template <class T>
void LinkedList<T>::setToEnd()//O(n)
{
    if(curr_pos==tail && tail!=head)
    {
        prev();
        return;
    }
    else if(curr_pos==tail && tail==head)
    {
        return;
    }
    while(curr_pos->next!=tail)
    {
        curr_pos = curr_pos->next;
    }
}

template <class T>
void LinkedList<T>::prev()//O(n)
{
    if(curr_pos==head)
    {
        return;
    }
    Node<T> *temp = head;
    while(temp->next!=curr_pos)
    {
        temp = temp->next;
    }
    curr_pos = temp;
}

template <class T>
void LinkedList<T>::next()//O(1)
{
    if(curr_pos->next==tail)
    {
        return;
    }
    curr_pos = curr_pos->next;
}

template <class T>
int LinkedList<T>::currPos()//O(n)
{
    int pos =0;
    Node<T> *temp = head;
    while(temp!=curr_pos)
    {
        temp = temp->next;
        pos++;
    }
    return pos;
}

template <class T>
void LinkedList<T>::setToPos( int pos)//O(n)
{
    if(pos>=0 && pos < this->size())
    {
        curr_pos = head;
        for(int i =0; i<pos; i++)
        {
            curr_pos = curr_pos->next;
        }
    }

}

template <class T>
T LinkedList<T>::getValue()//O(1)
{
    if(curr_pos!=NULL && curr_pos->next!=NULL)
    {
      return curr_pos->next->data;
    }
   // else
     //   return -1;
}

template <class T>
int LinkedList<T>::find(T Data)//O(n)
{
    Node<T> *temp = head->next;
    int pos = 0;
    while(temp!=NULL)
    {
        if(temp->data==Data)
            return pos;
        temp=temp->next;
        pos++;
    }
    return -1;
}

template <class T>
void LinkedList<T>::clear()//O(n)
{
    this->setToBegin();
    while(head->next!=NULL)
    {
        erase();
    }
    tail=head;
    curr_pos = head;
}

template <class T>
ostream &operator <<(ostream &os,LinkedList<T> &llist)
{
    Node<T> *temp = llist.head->next;
    int currentPos = llist.currPos();
    os<<"< | ";
    for(int i = 0; i<llist.size(); i++)
    {
        os<<temp->data<<" ";
        temp = temp->next;
    }
    os<<">";
    return os;
}
#endif // HeaderL
