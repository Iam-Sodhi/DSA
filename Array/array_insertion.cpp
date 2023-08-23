#include <iostream>
// Traversal and insertion in array
using namespace std;
// Traversal
void display(int arr[], int a_size)
{
    for (int i = 0; i < a_size; i++)
    {
        cout << arr[i] << " ";
    }
}
void Ar_insertion(int arr[], int used_size, int total_size, int element, int index)
{
    if (used_size < total_size)
    {
        for (int i = used_size -1; i >= index; i--)
        {
            arr[i + 1] = arr[i];
        }
        arr[index]=element;
        cout << "Your array has been updated" << endl;
    }
    else
    {
        cout << "Sorry, Your array has insufficient space for insertion" << endl;
    }
}
int main()
{
    int arr[100] = {1, 3, 5, 6, 10};
    int size = 5;
    int element = 4;
    int index = 3;
    display(arr,size);
    cout<<endl;
    Ar_insertion(arr,size,100,element,index);
    size+=1;
    cout<<"Displaying the updated array:"<<endl;
    display(arr,size);
    return 0;
}