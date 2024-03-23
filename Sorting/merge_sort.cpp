#include <iostream>
using namespace std;
//O(nlogn)
void merge(int a[], int low, int high, int mid)
{
    int i, j, k;
    i = low;
    j = mid + 1;
    k = low;
    int b[high];
    while (i <= mid && j <= high) // Remember to use = sign as they are index
    {
        if (a[i] < a[j])
        {
            b[k] = a[i];
            i++;
            k++;
        }
        else
        {
            b[k] = a[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        b[k] = a[i];
        i++;
        k++;
    }
    while (j <= high)
    {
        b[k] = a[j];
        j++;
        k++;
    }
    for (int i = low; i < high + 1; i++) // size of array is high +1
    {
        a[i] = b[i];
    }
}
void Merge_sort(int a[], int low, int high) // here high is last index not the size
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        Merge_sort(a, low, mid); // here firstly call the recursion then use merge unlike quick sort
        Merge_sort(a, mid + 1, high);
        merge(a, low, high, mid);
    }
}
int main()
{
    int a[8] = {4, 5, 2, 56, 67, 32, 75, 98};
    int n = 8;
    Merge_sort(a, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}