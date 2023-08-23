#include <iostream>
using namespace std;
// For a given array and integers K & X, find the maximum sum
// subarray of size K and having sum less than X.
// Our approach has complexibility has O(n)
int maxsum(int a[], int n, int k, int x)
{
    int sum = 0;
    int ans = INT8_MAX;
    int i;
    for (i = 0; i < k; i++)
    {
        sum += a[i];
    }
    while (i < n)
    {
        if (sum < x)
        {
            ans = sum;
        }
        sum -= a[i - k];
        sum += a[i];
        i++;
    }
    return ans;
}
int main()
{
    int a[] = {7, 5, 4, 6, 8, 9};
    int n=sizeof(a)/sizeof(a[0]);
    int k = 3;
    int x = 20;
    cout<<maxsum(a,n,k,x);
    return 0;
}