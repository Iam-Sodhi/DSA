#include <iostream>
using namespace std;
void display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void arr_deletion(int arr[], int size, int index)
{
    for (int j = index; j < size - 1; j++)
    {
        arr[j] = arr[j + 1];
    }
   
}
int main()
{
    int arr[] = {1, 32, 43, 53, 66, 63, 98};
    int size_array = sizeof(arr) / sizeof(int); // it gives you no of elements in the array
    int index = 2;
    display(arr, size_array);
    arr_deletion(arr, size_array, index);
    size_array -= 1;
    display(arr, size_array);

    return 0;
}