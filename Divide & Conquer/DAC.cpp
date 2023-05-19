#include <bits/stdc++.h>
using namespace std;

int counter = 0;
vector <pair<int,int>> pairs;

void Merge(int arr[],int first,int mid,int last)
{
    int arr1[mid-first+1];
    int arr2[last-mid];
    for (int i= 0; i< (mid-first+1); i++)
    {
        arr1[i] = arr[first+i];
    }
    for (int i=0; i<(last-mid); i++)
    {
        arr2[i] = arr[mid+1+i];
    }
    int i = 0;
    int j = 0;
    int k =first;
    while(i < (mid-first+1) && j < (last-mid) )
    {
        if(arr1[i]<=arr2[j])
        {
            arr[k] = arr1[i];
            k++;
            i++;
        }
        else
        {
            counter+= mid - first +1 -i;
            for(int p = i; p<(mid-first+1); p++)
            {
                pairs.push_back({arr1[p],arr2[j]});
            }
            arr[k] = arr2[j];
            j++;
            k++;
        }
    }
    while(i<(mid-first+1))
    {
        arr[k] = arr1[i];
        i++;
        k++;
    }
    while(j<(last-mid))
    {
        arr[k] = arr2[j];
        j++;
        k++;
    }
}


void devideANDconquer(int arr[],int first, int last)
{
    if(last>first)
    {
        int mid = (last+first)/2;
        devideANDconquer(arr,first,mid);
        devideANDconquer(arr,mid+1,last);
        Merge(arr,first,mid,last);
    }
    else
        return;
}


int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i =0; i<n; i++)
    {
        cin>>arr[i];
    }
    devideANDconquer(arr,0,n-1);
    cout<<counter<<endl;
    cout<<"The inverted pairs are ";
    for(int i =0;i<pairs.size();i++)
    {
        cout<<"("<<pairs[i].first<<","<<pairs[i].second<<") ";
    }
    cout<<endl;
    return 0;
}

