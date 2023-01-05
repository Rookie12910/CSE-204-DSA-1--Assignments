#include<iostream>
#include<fstream>
#include "MyList.h"
#include "LinkedList.h"
#include "ArrayList.h"

using namespace std;
int main()
{
    int  K,X,Q,F,P;
    ifstream ifile;
    ofstream ofile;
    ifile.open("list_input.txt");
    ofile.open("list_output.txt");
    ifile>>K>>X;
    ArrayList <int> tempList(X);
    //LinkedList <int> tempList;
    for(int i =0; i<K; i++)
    {
        int data;
        ifile>>data;
        tempList.pushBack(data);
    }
    ArrayList <int> List(tempList,X);
    //LinkedList <int> List(tempList);
    ofile<<List<<"\n";
    ifile>>Q;
    for (int j =0; j<Q; j++)
    {
        ifile>>F>>P;
        switch(F)
        {
        case 1:
        {
            ofile<<List<<"\n";
            ofile<<List.size()<<"\n";
            break;
        }

        case 2:

        {
            List.push(P);
            ofile<<List<<"\n";
            ofile<<"-1"<<"\n";
            break;
        }

        case 3:
        {
            List.pushBack(P);
            ofile<<List<<"\n";
            ofile<<"-1"<<"\n";
            break;
        }
        case 4:
        {
            int erasedData = List.erase();
            ofile<<List<<"\n";
            ofile<<erasedData<<"\n";
            break;
        }
        case 5:
        {
            List.setToBegin();
            ofile<<List<<"\n";
            ofile<<"-1"<<"\n";
            break;
        }
        case 6:
        {
            List.setToEnd();
            ofile<<List<<"\n";
            ofile<<"-1"<<"\n";
            break;
        }
        case 7:
        {
            List.prev();
            ofile<<List<<"\n";
            ofile<<"-1"<<"\n";
            break;
        }
        case 8:
        {
            List.next();
            ofile<<List<<"\n";
            ofile<<"-1"<<"\n";
            break;
        }
        case 9:
        {
            ofile<<List<<"\n";
            ofile<<List.currPos()<<"\n";
            break;
        }
        case 10:
        {
            List.setToPos(P);
            ofile<<List<<"\n";
            ofile<<"-1"<<"\n";
            break;
        }
        case 11:
        {
            ofile<<List<<"\n";
            ofile<<List.getValue()<<"\n";
            break;
        }
        case 12:
        {
            ofile<<List<<"\n";
            ofile<<List.find(P)<<"\n";
            break;
        }
        case 13:
        {
            List.clear();
            ofile<<List<<"\n";
            ofile<<"-1"<<"\n";
            break;

        }
        }
    }
    ifile.close();
    ofile.close();
    return 0;
}
