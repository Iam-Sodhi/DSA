#include <iostream>
using namespace std;
// Find square root of a function using binary search with****precision*****
long long int tempSquareRoot(int n)
{
    int s = 0;
    int e = n;
   long long int ans;  // as mid* mid can be a huge value of the range of integer
   long long int mid; 
    while (s <= e)
    {
        mid = (s + e) / 2;
        if (mid * mid <= n)
        {
            ans = mid;
            if (mid * mid == n)
            {
                return mid;
            }

            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
    return ans;
}
double morePrecision(int n,int  tempans, int precision)
{
    double factor = 1;
    double ans=tempans;
    for (int i = 0; i < precision; i++)
    {
        factor /= 10;
        for ( double j = ans; j*j<n; j=j+factor)
        {    ans=j;
        }
    }
    return ans;
}
int main()

{
    int n;
    cin >> n;
    cout<<"Enter the no of Decimal Points upto which you want the square root: "<<endl;
    int precision;
    cin>>precision;
    int tempans=tempSquareRoot(n);
     cout<<"The Square Root of the provided number is "<<morePrecision(n,tempans,precision);
    return 0;
}