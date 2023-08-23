#include <iostream>
using namespace std;
// Pair sum problem  -> two approaches
bool bruteforce(int a[], int n, int k)
{
    // brute force approach
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (a[i] + a[j] == k)
            {
                return true;
            }
        }
    }
    return false;
}
// *****Second approach works for ****sorted array***** bit is more efficient
bool pairsum(int a[], int n, int k)
{
    int l = 0;
    int h = n - 1;
    while (l < h)
    {
        if ((a[l] + a[h]) == k)
        {
            cout << "The index of the pair are: " << l << " " << h << endl;

            return true;
        }

        else if ((a[l] + a[h]) > k)
        {
            h--;
        }

        else
        {
            l++;
        }
    }
    return false;
}
int main()

{
    int n = 8;
    int a[n] = {2, 4, 7, 11, 14, 16, 20, 21};
    int k = 31;
    // cout<<bruteforce(a,n,k);
    cout << pairsum(a, n, k); // works for sorted array
    return 0;
}