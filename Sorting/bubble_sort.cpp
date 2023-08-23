#include <iostream>
using namespace std;
void Bubble_sort(int* a, int n){
    int isSorted=0;
    for (int i = 0; i < n - 1; i++)  //n-1 passes
    {     isSorted=1; // to make bubble sort adaptive by default it is not
        for (int j = 0; j < n - 1 - i; j++)
        {   
            if (a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                isSorted=0;
            }
        }
        if (isSorted)
        {
            return ;
        }
        
    }
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
     Bubble_sort(arr,n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}