#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
// Reduce the given array
bool comparable(pair<int,int> v1, pair<int,int> v2){
    return v1.first< v2.first;  //to sort the first elements of pair in ascending order
}
int main()
{
    int arr[] = {10, 16, 7, 14, 5, 3, 12, 9};
    vector<pair<int, int>> v;
    int n=sizeof(arr)/sizeof(arr[0]);
    for (int i = 0; i < n; i++)
    {   v.push_back(make_pair(arr[i],i));
       //or 
       // pair<int,int> p;  p.first=arr[i];   p.second=i;   v.push_back(p);
    }
    
    sort(v.begin(),v.end(),comparable); // we can also do it here comparable is sort as the way we like
    // till now , we have got the sorted array and elements are with their original index

    // now it's time to reduce the array
    for (int i = 0; i < n; i++)
    {
        arr[v[i].second]=i;
    }


    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    return 0;
}