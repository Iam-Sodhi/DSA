#include <iostream>
using namespace std;
// You have been given a *****Sorted Array******** .Find the first and last occurence of 'K' in array.
// OR******Find total no of occurence of k in sorted array.
int firstOccurence(int a[], int n, int k)
{
    int s = 0;
    int e = n - 1;
    int ans;
    while (s <= e)
    {
        int mid = s + (e - s) / 2; // As sometimes (s+e) goes out of range
        if (a[mid] >= k)
        {
            ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    return ans;
}
int lastOccurence(int a[], int n, int k)
{
    int s = 0;
    int e = n - 1;
    int ans;
    while (s <= e)
    {
        int mid = s + (e - s) / 2; // As sometimes (s+e) goes out of range
        if (a[mid] <= k)
        {
            ans = mid;
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
    return ans;
}
int main()
{
    int a[] = {1, 1, 3, 3, 3,3,4, 5};
    int n = sizeof(a) / sizeof(a[0]);
    int k=3;
     int firstOcc=firstOccurence(a,n,k);
     int lastOcc=lastOccurence(a,n,k);
     cout<<"The first occurence : "<<firstOcc<<" & last occurence : "<<lastOcc<<endl;
     cout<<"The total occurence of "<<k<<" are "<<lastOcc-firstOcc+1<<endl;
    return 0;
}