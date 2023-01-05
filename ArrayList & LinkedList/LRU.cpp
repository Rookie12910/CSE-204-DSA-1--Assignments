#include<iostream>
#include<fstream>
#include "MyList.h"
#include "ArrayList.h"
#include "LinkedList.h"

using namespace std;

template <class K, class V>
class Pair
{
   private:
       K key;
       V value;
   public:
    void setPair(K key, V value)
    {
        this->key = key;
        this->value = value;
    }
    K getKey()
    {
        return key;
    }
    V getValue ()
    {
            return value;
    }
    bool operator == (Pair<K,V> ob);
    bool operator != (Pair<K,V> ob);
};


template <class K, class V>
bool Pair<K,V>:: operator ==(Pair<K,V> ob)
{
    return this->key==ob.key;
}

template <class K, class V>
bool Pair<K,V>:: operator !=(Pair<K,V> ob)
{
    return this->key!=ob.key;
}

template <class K, class V>
class LRUCache
{
private:
    //ArrayList <Pair<K,V>> *cache;
    LinkedList<Pair<K,V>> *cache;
    int capacity;
    int currSize;
public:
    LRUCache (int capacity)
    {
        //cache = new ArrayList<Pair<K,V>>(capacity);
        cache = new LinkedList<Pair<K,V>>;
        currSize = 0;
        this->capacity = capacity;
    }
    V get (K key);
    void put(K key, V value);
};

template <class K, class V>
V LRUCache<K,V>::get(K key)
{
   V temp;
   cache->setToBegin();
   while(cache->getValue().getKey()!=key && cache->currPos()!=(cache->size()-1))
   {
       cache->next();
   }
   if(cache->getValue().getKey()==key)
   {
       Pair<K,V> ob = cache->getValue();
       temp = cache->erase().getValue();
       cache->pushBack(ob);
       return temp;
   }
   return -1;

}

template <class K, class V>
void LRUCache<K,V>::put(K key, V value)
{
   currSize++;
   if(currSize>capacity)
   {
       cache->setToBegin();
       cache->erase();
       currSize--;
   }
       Pair<K,V> ob;
       ob.setPair(key,value);
       int position =cache->find(ob);
       if(position!=-1)
       {
           cache->setToPos(position);
           cache->erase();
       }
       cache->pushBack(ob);
}


int main()
{
    int C,Q,Oprtn,K,V;
    ifstream ifile;
    ofstream ofile;
    ifile.open("lru_input.txt");
    ofile.open("lru_output.txt");
    ifile>>C>>Q;
    LRUCache<int,int> LruCache(C);
    for(int i =0;i<Q;i++)
    {
        ifile>>Oprtn;
        if(Oprtn==1)
        {
            ifile>>K;
        }
        else if(Oprtn==2)
        {
            ifile>>K>>V;
        }
        switch(Oprtn)
        {
        case 1:
            {
              ofile<<LruCache.get(K)<<"\n";
              break;
            }
        case 2:
            {
                LruCache.put(K,V);
                break;
            }

        }
    }
    return 0;
}
