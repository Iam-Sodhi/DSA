#include <iostream>
using namespace std;
int linear_search(int arr[], int size, int element)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == element)
        {
            return i;
        }
    }
    return 0;
}
int binary_search(int arr[], int size, int element)
{
    int low = 0;
    int high = size - 1;
    int mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == element)
        {
            return mid;
        }
        else if (arr[mid] < element)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}
int main()
{
    //  // Unsorted array for linear search
    // int arr[] = {1, 23, 34, 31, 643, 639, 876, 32, 24, 56};
    // int size_array = sizeof(arr) / sizeof(int);
    // int element = 31;
    // cout << "The element " << element << " is found at index " << linear_search(arr, size_array, element);

    // Sorted array for binary search
    int arr[] = {2, 3, 5, 8, 10, 14, 23, 33, 36, 56, 67, 79, 89};
    int size_array = sizeof(arr) / sizeof(int);
    int element = 23;
    cout << "The element " << element << " is found at index " << binary_search(arr, size_array, element);

    return 0;
}