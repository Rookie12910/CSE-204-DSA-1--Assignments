#include <iostream>
#include <cstring>
#include<fstream>
#define default_index 1
#define default_value -2147483648

using namespace std;

ifstream ifile;
ofstream ofile;

class BST
{
public:
    int *bst;
    int  capacity;
    BST()
    {
        capacity = 100;
        bst = new int[capacity];
        fill_n(bst,capacity,default_value);
    }
    void Insert(int data,int index);
    bool Delete(int data,int index);
    bool Find (int data,int index);
    void Traversal (string type,int index);
    void Print(int index);
};

void BST::Insert(int data,int index)
{
    if(2*index+1>=capacity || 2*index>=capacity)
    {
        int*temp = new int[capacity*2];
        for(int i =0; i<capacity; i++)
        {
            temp[i]=bst[i];
        }
        for(int i =capacity; i<2*capacity; i++)
        {
            temp[i]=default_value;
        }
        delete []bst;
        bst = temp;
        capacity*=2;
    }
    if(bst[index]==default_value)
    {
        bst[index]= data;
        return;
    }
    else if(data<bst[index])
        Insert(data,index*2);
    else if(data>bst[index])
        Insert(data,(index*2)+1);
}
bool BST::Delete(int data,int index)
{
    if(bst[index]==data && (bst[index*2]!=default_value || bst[(index*2)+1]!=default_value))
    {
        ofile<<"Invalid Operation"<<"\n";
        return false;
    }
    if(index>capacity && bst[index]!=data)
    {
      ofile<<"Invalid Operation"<<"\n";
      return false;
    }

    if(bst[index]==data && bst[index*2]==default_value && bst[(index*2)+1]==default_value)
    {
        bst[index] = default_value;
        return true;
    }

    else if(data<bst[index])
        Delete(data,index*2);
    else if(data>bst[index])
        Delete(data,(index*2)+1);
}
bool BST::Find(int data,int index)
{
    if(index>=capacity)
        return false;
    if(bst[index]==data)
        return true;
    else if(data<bst[index])
        Find(data,index*2);
    else if(data>bst[index])
        Find(data,(index*2)+1);
}
void BST::Traversal(string type,int index)
{
    if(type=="In")
    {
        if(bst[index]!=default_value)
        {
            Traversal(type,index*2);
            ofile<<bst[index]<<" ";
            Traversal(type,(index*2)+1);
        }
    }
    if(type=="Pre")
    {
        if(bst[index]!=default_value)
        {
            ofile<<bst[index]<<" ";
            Traversal(type,index*2);
            Traversal(type,(index*2)+1);
        }
    }
    if(type=="Post")
    {
        if(bst[index]!=default_value)
        {
            Traversal(type,index*2);
            Traversal(type,(index*2)+1);
            ofile<<bst[index]<<" ";
        }
    }

}

void BST::Print(int index)
{
    if(bst[index]!=default_value && bst[index*2]==default_value && bst[(index*2)+1]==default_value)
    {
        ofile<<bst[index];
        Print(index*2);
        Print((index*2)+1);
    }
   else if(bst[index]!=default_value && (bst[index*2]!=default_value || bst[(index*2)+1]!=default_value))
    {
        ofile<<bst[index];
        ofile<<"(";
        Print(index*2);
        ofile<<")";
        ofile<<"(";
        Print((index*2)+1);
        ofile<<")";
    }
}

int main()
{
    BST bst;
    ifile.open("input.txt");
    ofile.open("output.txt");
    char operation;
    while(ifile.peek()!=EOF)
    {
        ifile>>operation;
        switch(operation)
        {
        case 'I':
        {
            int data;
            ifile>>data;
            bst.Insert(data,default_index);
            bst.Print(default_index);
            ofile<<"\n";
            break;
        }
        case 'D':
        {
            int data;
            ifile>>data;
            if(bst.Delete(data,default_index))
            {
            bst.Print(default_index);
            ofile<<"\n";
            }
            break;
        }
        case 'F':
        {
            int data;
            ifile>>data;
            if(bst.Find(data,default_index))
                ofile<<"True"<<"\n";
            else
                ofile<<"False"<<"\n";
            break;
        }
        case 'T':
        {
            string type;
            ifile>>type;
            bst.Traversal(type,default_index);
            ofile<<"\n";
            break;
        }
        }
    }

    return 0;
}
