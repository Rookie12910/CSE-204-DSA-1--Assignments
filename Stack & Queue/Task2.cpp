#include<iostream>
#include<fstream>
#include "ArrayQueue.h"
#include "ArrayStack.h"
#include "LinkedStack.h"
#include "LinkedQueue.h"
using namespace std;

class customer
{
public:
    customer()
    {
        id = entry_time = renting_time = exit_time = -1;
    }
    int id;
    int entry_time;
    int renting_time;
    int exit_time;
    customer operator = (customer Customer);
};
customer customer::operator=(customer Customer)
{
    id = Customer.id;
    entry_time = Customer.entry_time;
    renting_time = Customer.renting_time;
    exit_time = Customer.exit_time;
    return *this;
}
int customer_id(int time, customer customers[],int n)
{
    for(int i = 1; i<=n; i++)
    {
        if(time==customers[i].entry_time)
        {
            return customers[i].id;
        }
    }
    return -1;
}

int main()
{
    int n,c,s,d,time;
    ifstream ifile;
    ofstream ofile;
    ifile.open("task2input.txt");
    ofile.open("task2output.txt");
    ifile>>n>>c;
    customer customers[n];
    //ArrayStack <customer> Stack(n);
    //ArrayQueue <customer> Queue(n);
    LinkedStack <customer> Stack;
    LinkedQueue <customer> Queue;
    for(int i =1; i<=n; i++)
    {
        ifile>>s>>d;
        customers[i].id = i;
        customers[i].entry_time = s;
        customers[i].renting_time = d;
    }
    int console1_taken = 0;
    int console2_taken = 0;
    int console1_releaseat = -1;
    int console2_releaseat = -1;
    for(time = 0; time<=c; time++)
    {
        if(time==console1_releaseat && console1_taken==1)
        {
            customer Customer;
            if(Queue.length()>0)
            {
                Customer  = Queue.dequeue();
                customers[Customer.id].exit_time = time + customers[Customer.id].renting_time;
                console1_releaseat = customers[Customer.id].exit_time;
            }
            else if(Queue.length()==0)
            {
                console1_taken = 0;
            }
        }
        if(time==console2_releaseat &&  console2_taken==1)
        {
            customer Customer;
            console2_taken = 0;
            if(customer_id(time,customers,n)!=-1 && console1_taken==1 && Queue.length()>=3 && console2_taken==0)
            {
                console2_taken = 1;
                customers[customer_id(time,customers,n)].exit_time = time + customers[customer_id(time,customers,n)].renting_time;
                console2_releaseat = time + customers[customer_id(time,customers,n)].renting_time;
                time++;
                continue;

            }
            else
            {
                if(Stack.length()>0)
                {
                    console2_taken = 1;
                    Customer  = Stack.pop();
                    customers[Customer.id].exit_time = time + customers[Customer.id].renting_time;
                    console2_releaseat = customers[Customer.id].exit_time;
                }
                else if(Stack.length()==0)
                {
                    console2_taken = 0;
                }

            }

        }


        if(customer_id(time,customers,n)!=-1 && console1_taken==0)
        {
            console1_taken = 1;
            customers[customer_id(time,customers,n)].exit_time = time + customers[customer_id(time,customers,n)].renting_time;
            console1_releaseat = time + customers[customer_id(time,customers,n)].renting_time;
        }
        else if(customer_id(time,customers,n)!=-1 && console1_taken==1 && Queue.length()<3)
        {
            Queue.enqueue(customers[customer_id(time,customers,n)]);
        }
        else if(customer_id(time,customers,n)!=-1 && console1_taken==1 && Queue.length()>=3 && console2_taken==0)
        {
            console2_taken = 1;
            customers[customer_id(time,customers,n)].exit_time = time + customers[customer_id(time,customers,n)].renting_time;
            console2_releaseat = time + customers[customer_id(time,customers,n)].renting_time;
        }
        else if(customer_id(time,customers,n)!=-1 && console1_taken==1 && Queue.length()>=3 && console2_taken==1)
        {
            Stack.push(customers[customer_id(time,customers,n)]);
        }

    }
    for(int i =1; i<=n; i++)
    {
        if(customers[i].exit_time>c)
        {
            customers[i].exit_time = c;
        }
        ofile<<customers[i].id<<" > "<<customers[i].exit_time<<"\n";
    }
    return 0;
}
