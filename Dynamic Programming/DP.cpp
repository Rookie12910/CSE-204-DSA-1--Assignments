#include<bits/stdc++.h>
using namespace std;

void sackTable(int **p,int wt[],int v[],int w, int n)
{
    for(int i = 0; i<=w; i++)
    {
        p[0][i] = 0;
    }
    for(int i = 0; i<=n; i++)
    {
        p[i][0] = 0;
    }
    for(int i =1; i<=n; i++)
    {
        for(int j = 1; j<=w; j++)
        {
            if(wt[i-1]<=j)
            {
                if(v[i-1]+p[i-1][j-wt[i-1]] > p[i-1][j])
                {
                    p[i][j] = v[i-1]+p[i-1][j-wt[i-1]];
                }

                else
                    p[i][j] = p[i-1][j];
            }
            else
                p[i][j] = p[i-1][j];

        }
    }
}

int knapSack(int wt[],int v[],int w, int n,vector <int> &items)
{
    int **p;
    int index,used_wt;
    p = new int*[n+1];
    for(int i =0; i<n+1; i++)
    {
        p[i] = new int[w+1];
    }
    sackTable(p,wt,v,w,n);
    int Max = p[0][0];
    for(int i =0;i<=n;i++)
    {
        for(int j =0;j<=w;j++)
        {
            if(p[i][j]>Max)
            {
                Max = p[i][j];
                index = i;
                used_wt = j;
            }
        }
    }
    items.push_back(wt[index-1]);
    used_wt-=wt[index-1];
    int j = index;
    while(index > 1)
    {
        index--;
        if(p[index][used_wt]>p[index-1][used_wt])
        {
            items.push_back(wt[index-1]);
            used_wt-=wt[index-1];
            j = index;
        }
    }
    return Max;
}

int main()
{
    ifstream ifile;
    ofstream ofile;
    ifile.open("input.txt");
    ofile.open("output.txt");
    int n,w;
    ifile>>n;
    int v[n];
    int wt[n];
    for(int i=0;i<n;i++)
    {
        ifile>>wt[i]>>v[i];
    }
    ifile>>w;
    vector <int> items;
    ofile<<knapSack(wt,v,w,n,items)<<endl;
    for(int i =items.size()-1;i>=0;i--)
        ofile<<items[i]<<" ";
    ofile<<endl;
    return 0;
}
