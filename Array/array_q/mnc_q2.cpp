#include <iostream>
using namespace std;
// Subarray with given sum
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int S;
    cout << "Enter the given sum: ";
    cin >> S;
    int i = 0, j = 0, st = -1, en = -1, sum = 0;
    while (sum +arr[j] <= S && j < n)
    {
        sum += arr[j];
        j++;
    }
    if (sum == S)
    {
        cout << "Starting position: " << i + 1 << " & Ending position: " << j;
    }
    // else
    while (j < n)
    {   sum+=arr[j];
        while (sum > S)
        {
            sum -= arr[i];
            i++;
        }
        if (sum == S)
        {
            st = i + 1; // becouse st and en are position that's why we add 1
            en = j+1 ;
            break;
        }
        j++;
    }
   cout<<"Starting position: "<<st<<" & Ending position: "<<en<<endl;
    return 0;
}