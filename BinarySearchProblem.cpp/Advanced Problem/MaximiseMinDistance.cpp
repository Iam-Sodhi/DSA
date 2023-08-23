#include <iostream>
#include <algorithm>
using namespace std;
// Given is an array with n elements that represents n positions along a straight line.
// Find K(given) elements such that the min distance b/w any 2 elements is the maximum possible.
//*****Aggresive Cows Problem******
bool isfeasible(int a[], int n, int k, int mid)
{
    int x = a[0];
    int cowcount = 1;
    for (int i = 0; i < n; i++)
    {

        if (a[i] - x >= mid)
        {
            cowcount++;
            if (cowcount == k)
            {
                return true;
            }
            x = a[i];
        }
    }

    return false;
}
int largestMinDistance(int a[], int n, int k)
{
    sort(a, a + n);
    int result = -1;
    int left = a[0];
    int right = a[n - 1];
    int mid;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (isfeasible(a, n, k, mid)) // means now find larger distance
        {
            result = mid;
            left = mid + 1; // right part as maximum is needed
        }
        else
        {
            right = mid - 1; 
        }
    }
    return result;
}
int main()
{
    //int a[] = {1, 2, 8, 4, 9};
   int a[] = {11, 2, 7, 5, 1, 12};
    int n = sizeof(a) / sizeof(a[0]);
    int k = 3;
    cout << largestMinDistance(a, n, k);
    return 0;
}