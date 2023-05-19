#include <iostream>
#include<fstream>
#include "ArrayQueue.h"

using namespace std;

ifstream ifile;
ofstream ofile;

enum Color{black,grey,white};
#define infinity 1000000
#define N 100

class vertex
{
    public:
    int vertex_value;
    Color color;
    int distance;
    int child[N];
    int child_count;
    int parent;
    int itime;
    int ftime;
    vertex()
    {
       vertex_value = 0;
       color = white;
       distance = infinity;
       parent = 0;
       child_count = 0;
       itime = 0;
       ftime = 0;
    }
    vertex(int value)
    {
       vertex_value = value;
       color = white;
       distance = infinity;
       parent = 0;
       child_count = 0;
       itime = 0;
       ftime = 0;
    }
    vertex operator = (vertex v);
    bool operator ==(vertex v);
};
vertex vertex::operator=(vertex v)
{
       vertex_value = v.vertex_value;
       color = v.color;
       distance = v.distance;
       parent = v.parent;
       for(int i =0;i<v.child_count;i++)
       {
           child[i] = v.child[i];
       }
       child_count = v.child_count;
       itime = v.itime;
       ftime = v.ftime;
       return *this;
}

bool vertex::operator==(vertex v)
{
    if(vertex_value==v.vertex_value)
        return true;
    else
        return false;
}

void BFS(vertex graph[],vertex s,int n, int m)
{
    ofile<<"BFS Tree :"<<endl;
    ofile<<"Predecessor subgraph of G as Gp = (V,Ep) :"<<endl;
    graph[s.vertex_value].color = grey;
    graph[s.vertex_value].distance = 0;
    ArrayQueue<vertex> q(n);
    q.enqueue(graph[s.vertex_value]);
    int vertices[n];
    int edges [m][2];
    int counter1 = 0;
    int counter2 = 0;
    while(q.length()!=0)
    {
        vertex u = q.dequeue();
        vertices[counter1++] = u.vertex_value;
        for (int i=0;i<u.child_count;i++)
        {
            int k = u.child[i];
            if(graph[k].color==white)
            {
                edges[counter2][0] = u.vertex_value;
                edges[counter2][1] = k;
                counter2++;
                graph[k].color = grey;
                graph[k].distance = u.distance+1;
                graph[k].parent = u.vertex_value;
                q.enqueue (graph[k]);
            }
        }
        u.color = black;
    }
    ofile<<"V = ( ";
    for(int i =0;i<counter1;i++)
    {
        ofile<<vertices[i]<<" ";
    }
    ofile<<")"<<endl;
    ofile<<"Ep = "<<endl<<"{ "<<endl;
    for(int i =0;i<counter2;i++)
    {
        ofile<<"("<<edges[i][0]<<" -> "<<edges[i][1]<<") "<<endl;
    }
    ofile<<"}"<<endl<<endl;
}


void DFS_visit(vertex graph[], vertex &u, int edges[][2],int &counter, int &Time);

void DFS(vertex graph[],int src,int n,int m)
{
    int edges[m][2];
    int counter = 0;
    int Time = 0;
    ofile<<"DFS Tree :"<<endl;
    ofile<<"Predecessor subgraph of G as Gp = (V,Ep) :"<<endl;
    ofile<<"V = ( ";
    if(graph[src].color==white)
    {
       DFS_visit(graph,graph[src],edges,counter,Time);
    }
    for(int i =0;i<n;i++)
    {
        if(graph[i].color==white)
        {
            DFS_visit(graph,graph[i],edges,counter,Time);
        }
    }
    ofile<<")"<<endl;
    ofile<<"Ep = "<<endl<<"{ "<<endl;
    for(int i =0;i<counter;i++)
    {
        ofile<<"("<<edges[i][0]<<" -> "<<edges[i][1]<<") "<<endl;
    }
    ofile<<"}"<<endl<<endl;
    Time = 0;
    counter = 0;
}

void DFS_visit(vertex graph[], vertex &u, int edges[][2],int &counter, int &Time)
{
  ofile<<u.vertex_value<<" ";
  Time++;
  u.itime = Time;
  u.color = grey;
  for(int i=0;i<u.child_count;i++)
  {
      int k = u.child[i];
      if(graph[k].color == white)
      {
          edges[counter][0] = u.vertex_value;
          edges[counter][1] = k;
          counter++;
          graph[k].parent = u.vertex_value;
          DFS_visit(graph,graph[k],edges,counter,Time);
      }
  }
  u.color = black;
  Time++;
  u.ftime = Time;
}

void refresh(vertex graph[],int n)
{
  for(int i=0;i<n;i++)
    {
        graph[i].color = white;
        graph[i].distance = infinity;
        graph[i].parent = 0;
        graph[i].itime  = 0;
        graph[i].ftime = 0;
    }
}

int main()
{
    ifile.open("input.txt");
    ofile.open("output.txt");
    int n,m,s;
    ifile>>n;
    ifile>>m;
    vertex *graph;
    graph = new vertex[n+1];
    for(int i =0;i<m;i++)
    {
        int u,v;
        ifile>>u;
        ifile>>v;
        if(graph[u].vertex_value==0)
        {
           graph[u].vertex_value = u;
        }
        if(graph[v].vertex_value==0)
        {
           graph[v].vertex_value = v;
        }
        graph[u].child[graph[u].child_count++] = v;
    }
    ifile>>s;
    BFS(graph,graph[s],n,m);
    refresh(graph,n);
    DFS(graph,s,n,m);
    refresh(graph,n);
    return 0;
}


