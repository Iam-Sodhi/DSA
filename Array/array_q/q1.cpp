#include <iostream>
#include <conio.h>
// Max number till ith term
using namespace std;
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the element at " << i << " index:";
        cin >> arr[i];
    }
    int max_num = INT8_MIN;
    int min_num = INT8_MAX;
    for (int i = 0; i < n; i++)
    {
        max_num = max(max_num, arr[i]);
        min_num = min(min_num, arr[i]);
        cout << "The minimum number till "<<i<<" term: " << min_num << endl;
        cout << "The maximum number till "<<i<<" term: " << max_num << endl;
        cout << endl;
    }

    return 0;
}