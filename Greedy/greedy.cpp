#include <iostream>
#include <fstream>
using namespace std;

class customer
{
public:
    int a_time;
    int d_time;
    customer operator =(customer p);
    bool operator==(customer p);
};

customer customer::operator=(customer p)
{
    a_time = p.a_time;
    d_time = p.d_time;
    return *this;
}

bool customer::operator==(customer p)
{
    if(a_time==p.a_time && d_time==p.d_time)
        return true;
    else
        return false;
}

void Sort(customer customers[],int Size)
{
    customer temp;
   for (int i =0;i<Size;i++)
   {
      for(int j =i;j<Size;j++)
      {
          if(customers[i].d_time > customers[j].d_time)
          {
              temp = customers[i];
              customers[i] = customers[j];
              customers[j] = temp;
          }
          else if(customers[i].d_time == customers[j].d_time)
          {
              if(customers[i].a_time>customers[j].a_time)
              {
                temp = customers[i];
              customers[i] = customers[j];
              customers[j] = temp;
              }

          }
      }
   }
}

void result(customer customers[], int Size, int deadend)
{
    customer served[Size];
    int served_count = 0;
    int index = 0;
    int time = 0;
    while(time<=deadend && index<Size)
    {
        if(customers[index].a_time>=time)
        {
           served[served_count++] = customers[index];
           time=customers[index].d_time;
           index++;
        }
        else index++;
    }
    cout<<served_count<<endl;
    for(int i =0;i<served_count;i++)
   {
      cout<<served[i].a_time<<" "<<served[i].d_time<<endl;
   }
}

int main()
{
   ifstream ifile;
   ofstream ofile;
   ifile.open("input.txt");
   ofile.open("output.txt");
   int n,t1,t2,deadend=0;
   ifile>>n;
   customer customers[n];
   for(int i =0;i<n;i++)
   {
      ifile>>t1>>t2;
      if(t2>deadend)
      {
          deadend = t2;
      }
      customers[i].a_time = t1;
      customers[i].d_time = t2;

   }
   Sort(customers,n);
   result(customers,n,deadend);
}
