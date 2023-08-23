#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
     int min_idx;
    for (int i = 0; i < n - 1; i++) // there are n-1 passes
    {
        // for (int j = i+1; j <n; j++)
        // {
        //     if (arr[j]<arr[i])
        //     {
        //         int temp=arr[i];
        //         arr[i]=arr[j];
        //         arr[j]=temp;
        //     }

        // }
        // OR
         min_idx=i;
        for (int j = i; j < n; j++)
        {
            if (arr[j] < arr[i])
            {
                min_idx = j;
            }
       
        }
        int temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
      
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}