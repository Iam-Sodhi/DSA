#include <iostream>
#include <math.h>
using namespace std;
// For a given array and an integer k , find the maximum perfect numbers in a subarray of size k.
// Perfect number is a number if it is equal to the sum of its proper diviisors(positive) except for the number itself.
bool isPerfectNum(int n)
{
    // We can either use simple approach to traverse from 1 to n-1 to check it it is divisor and then add them.
    // But here we will use more efficient approach
    int sum = 1;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            if (i * i == n)
            {
                sum += i;
            }
            else
            {
                sum = sum + i + n / i; // e.g. for 28, if 4 is divisor this method will also add 7 along with it(7*4=28)
            }
        }
    }
    if (sum == n && n != 1)
    {
        return true;
    }
    return false;
}
int MaxSum(int a[], int n, int k)
{
    if (n < k)
    {
        cout << "It is not possible ";
        return -1;
    }
    int sum = 0;
    int i;
    for (i = 0; i < k; i++)
    {
        sum += a[i];
    }
    int ans = sum;
    while (i < n)
    {
        ans += a[i] - a[i - k];
        sum = max(sum, ans);
    }

    return sum;
}
int MaxPerfectNum(int a[], int n, int k)
{
    // Firstly convert your array in form of 0 & 1
    for (int i = 0; i < n; i++)
    {
        if (isPerfectNum(a[i]))
        {
            a[i] = 1;
        }
        else
        {
            a[i] = 0;
        }
    }
    // NOw we just need to find subarray of size k having max sum
    return MaxSum(a, n, k);
}
int main()
{
    int a[] = {28, 2, 3, 6, 49, 99, 4, 24};
    int k = 4;
    int n = 8;
    int ans = MaxPerfectNum(a, n, k);
    cout << ans;
    return 0;
}