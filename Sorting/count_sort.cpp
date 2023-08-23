#include <iostream>
using namespace std;
// it has O(n) or O(n+m) where m is max element in array  time complexibility but it take excess memory
//O(max(n,m))  -. n is size of array and m is the max element
int maximum(int a[], int n)
{
    int max = INT8_MIN;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
        }
    }
    return max;
}
int count_sort(int a[], int n)
{
    // find max element
    int max = maximum(a, n);
    // make a count array of size max+1
    int *count = new int[max + 1];
    for (int i = 0; i < max + 1; i++)
    {
        count[i] = 0;
    }
    // increase the vlaue of count index as per the elements in the original array
    for (int i = 0; i < n; i++)
    {
        count[a[i]] += 1;
    }

    int i = 0, j = 0;
    for (int i = 0; i < max + 1; i++)
    {
        while (count[i] > 0)
        {
            a[j] = i;
            count[i] -= 1;
            j++;
        }
    }
}
int main()
{
    int a[] = {4, 2, 6, 7, 2, 9};
    int n = 6;
    count_sort(a, n);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}