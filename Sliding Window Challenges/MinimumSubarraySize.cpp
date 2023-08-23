#include <iostream>
using namespace std;
// For a given array and an integer x, find the subarray having minimum size for which sum>x
int minimumSizeSubarray(int a[], int n, int x)
{
    int st = 0;
    int en = 0;
    int ans = n + 1;
    int sum=0;
    while (en < n)
    {
        while (sum <= x && en < n)
        {
            sum += a[en++];
        }
        // now en is at index one step higher where sum>x
        //Hence length = en-st is not en-st+1
        while (sum > x && st < n)
        {
            if (en - st < ans)
            {
                ans= en - st ;
            }
            sum-=a[st++];
        }
    }
    return ans;
}
int main()
{   int a[]={1,4,45,6,10,19};
    int x=51;
    int n=6;
    cout<<"The smallest lenght subarray is: "<<minimumSizeSubarray(a,n,x);
    return 0;
}