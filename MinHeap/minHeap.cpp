#include <iostream>
#include <fstream>
#include<cstring>
#include <cmath>
using namespace std;

ifstream ifile;
ofstream ofile;

class minHeap
{
    int *heap;
    int curr_size;
    int capacity;
public:
    minHeap (int capacity)
    {
        this->capacity = capacity;
        heap = new int [capacity];
        curr_size = 0;
    }
    int FindMin();
    int ExtractMin();
    void Insert(int key);
    void DecreaseKey (int prevKey, int newKey);
    void Print();
    void Swap(int &a, int &b)
    {
        int temp;
        temp = a;
        a = b;
        b = temp;
    }
};

int minHeap::FindMin()
{
    if(curr_size==0)
    {
        return -1;
    }
    return heap[0];
}

int minHeap::ExtractMin()
{
    if(curr_size==0)
    {
        return -1;
    }
    int index = 0;
    int Min = heap[index];
    heap [index] = heap[curr_size-1];
    curr_size--;
    while((index*2)+1<=curr_size && (index*2)+2 <=curr_size)
    {
        if(heap[(index*2)+1]<heap[index] || heap[(index*2)+2]<heap[index])
        {
            if (heap[(index*2)+1] < heap[(index*2)+2])
            {
                Swap(heap[(index*2)+1],heap[index]);
                index = (index*2) +1;
            }

            else if (heap[(index*2)+2] <= heap[(index*2)+1])
            {
                Swap(heap[(index*2)+2],heap[index]);
                index = (index*2) + 2;
            }
        }

        else if(heap[index*2+1]>=heap[index] && heap[index*2+2]>=heap[index])
            break;
    }
    return Min;
}

void minHeap::Insert(int key)
{
    if (curr_size >= capacity)
    {
        int *tmp = new int[capacity*2];
        for(int i =0; i<capacity; i++)
        {
            tmp[i] = heap[i];
        }
        delete []heap;
        heap = tmp;
        capacity *=2;
    }
    int index = curr_size;
    heap[curr_size++] = key;
    while(heap[index] < heap[(index-1)/2] && index > 0)
    {
        Swap(heap[index],heap[(index-1)/2]);
        index = (index-1)/2;
    }

}

void minHeap::DecreaseKey(int prevKey,int newKey)
{
    if(prevKey<newKey)
    {
        ofile<<"Invalid input!"<<"\n";
        return;
    }
    int index;
    for(int i =0; i<=curr_size; i++)
    {
        if(heap[i] == prevKey)
        {
            index = i;
            break;
        }
        if(i==curr_size)
        {
            ofile<<"Key not Found"<<endl;
            return;
        }
    }
    heap[index] = newKey;
    while(heap[index] < heap[(index-1)/2] && index > 0)
    {
        Swap(heap[index],heap[(index-1)/2]);
        index = (index-1)/2;
    }
    ofile<<prevKey<<" decreased to "<<newKey<<"\n";
}

void minHeap::Print()
{
    int index = curr_size-1;
    int curr_index=0;
    int level = 0;
    while(index>0)
    {
        index = (index-1)/2;
        level++;
    }
    ofile<<"Printing the binary heap ..."<<endl;
    ofile<<"----------------------------------------------------------"<<endl;
    for (int i =0; i<=level; i++)
    {
        ofile<<"Level "<<i<<" : ";
        int Max = curr_index+pow(2,i);
        if(Max>curr_size)
            Max = curr_size;
        int initial = curr_index;
        for(int j =initial; j<Max; j++)
        {
            ofile<<heap[j]<<" ";
            curr_index++;
        }
        ofile<<endl;
    }
    ofile<<"----------------------------------------------------------"<<endl;
}

int main()
{
    minHeap heap(10);
    ifile.open("input.txt");
    ofile.open("output.txt");
    string operation;
    while(ifile.peek()!=EOF)
    {
        ifile>>operation;
        int param1,param2;

        if(operation=="INS")
        {
            ifile>>param1;
            heap.Insert(param1);
            ofile<<"Inserted "<<param1<<"\n";
        }
        else if(operation=="EXT")
        {
            int extracted_min = heap.ExtractMin();
            if(extracted_min==-1)
            {
                ofile<<"Heap is empty!"<<"\n";
            }
            else
                ofile<<"ExtractMin returned "<<extracted_min<<"\n";
        }
        else if(operation=="FIN")
        {
            int find_min = heap.FindMin();
            if(find_min==-1)
            {
                ofile<<"Heap is empty!"<<"\n";
            }
            else
                ofile<<"FindMin returned "<<find_min<<"\n";
        }
        else if(operation=="DEC")
        {
            ifile>>param1>>param2;
            heap.DecreaseKey(param1,param2);
        }
        else if(operation=="PRI")
        {
            heap.Print();
        }
    }
    return 0;
}
