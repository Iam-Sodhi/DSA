#include <iostream>
using namespace std;
//Worst Case – This case occurs when the pivot is the greatest or smallest element of the array. If the partition is done and the last element is the pivot, then the worst case would be either in the increasing order of the array or in the decreasing order of the array. O(n^2)
//Best Case – This case occurs when the pivot is the middle element or near to middle element of the array. O(nlogn)
int partition(int *a, int low, int high)
{
    int pivot = a[low];
    int i = low + 1;
    int j = high; int temp;
    do
    {
        while (a[i] <= pivot)
        {
            i++;
        }
        while (a[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
        
    } while (i < j);
    // swap a[low]and a[j]
    temp = a[j];
        a[j] = a[low];
        a[low] = temp;
        return j;
}
void quick_sort(int *a, int low, int high)
{
        int partition_index;
        if (low < high)
        {
            partition_index = partition(a, low, high);
            quick_sort(a, low, partition_index - 1);
            quick_sort(a, partition_index + 1, high);
        }
}
int main()
{
        int a[6] = {1, 4, 6, 3, 9, 2};
        int n = 6;
        quick_sort(a, 0, n - 1);
        
        
        for (int i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }

        return 0;
}