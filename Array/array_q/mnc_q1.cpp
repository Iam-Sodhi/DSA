#include <iostream>

using namespace std;
int main()
{	int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i <n; i++)
    {
        cin>>arr[i];
    }
    const int x=1e5;
    int idx[x];
    for (int i = 0; i < x; i++)
    {
        idx[i]=-1;
    }
    int minidx=INT8_MAX;
    for (int i = 0; i < n; i++)
    {
        if (idx[arr[i]]!=-1)
        {
           minidx= min(minidx,idx[arr[i]]);
        }
        else
        {
            idx[arr[i]]=i;
        }
        
    }
    if (minidx==INT8_MAX)
    {
        cout<<"-1";
    }
    else
    {
        cout<<minidx+1; // this will give position
    }
    
    
    return 0;
}