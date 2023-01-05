#include<iostream>
#include<fstream>
#include"ArrayStack.h"
#include"LinkedStack.h"
#include"ArrayQueue.h"
#include"LinkedQueue.h"
using namespace std;
int main()
{
    int K,X,M,Y,Q,F,P;
    ifstream ifile;
    ofstream ofile;
    ifile.open("input.txt");
    ofile.open("output.txt");
    ifile>>K>>X;
    //ArrayQueue <int> Queue(X);
    LinkedQueue <int> Queue;
    for(int i =0;i<K;i++)
    {
        int data;
        ifile>>data;
        Queue.enqueue(data);
    }
    ifile>>M>>Y;
    //ArrayStack <int> Stack(M);
    LinkedStack <int> Stack;
    for(int i =0;i<M;i++)
    {
        int data;
        ifile>>data;
        Stack.push(data);
    }
    ofile<<Queue<<"\n";
    ofile<<Stack<<"\n";

    ifile>>Q;
    for(int j = 0;j <Q;j++)
    {
        ifile>>F>>P;
        switch(F)
        {
        case 1:
        {
            Queue.clear();
            ofile<<Queue<<"\n";
            ofile<<"-1"<<"\n";
            break;
        }

        case 2:

        {

            Queue.enqueue(P);
            ofile<<Queue<<"\n";
            ofile<<"-1"<<"\n";
            break;
        }

        case 3:
        {
            int data = Queue.dequeue();
            ofile<<Queue<<"\n";
            ofile<<data<<"\n";
            break;
        }
        case 4:
        {

            ofile<<Queue<<"\n";
            ofile<<Queue.length()<<"\n";
            break;
        }
        case 5:
        {

            ofile<<Queue<<"\n";
            ofile<<Queue.frontValue()<<"\n";
            break;
        }
        case 6:
        {

            ofile<<Queue<<"\n";
            ofile<<Queue.rearValue()<<"\n";
            break;
        }
        case 7:
        {
            int data = Queue.leaveQueue();
            ofile<<Queue<<"\n";
            ofile<<data<<"\n";
            break;
        }
        case 8:
        {
            Stack.clear();
            ofile<<Stack<<"\n";
            ofile<<"-1"<<"\n";
            break;
        }
        case 9:
        {

            Stack.push(P);
            ofile<<Stack<<"\n";
            ofile<<"-1"<<"\n";
            break;
        }
        case 10:
        {
            int data = Stack.pop();
            ofile<<Stack<<"\n";
            ofile<<data<<"\n";
            break;
        }
        case 11:
        {
            ofile<<Stack<<"\n";
            ofile<<Stack.length()<<"\n";
            break;
        }
        case 12:
        {
            ofile<<Stack<<"\n";
            ofile<<Stack.topValue()<<"\n";
            break;
        }


}
        }
    ifile.close();
    ofile.close();
return 0;
}
