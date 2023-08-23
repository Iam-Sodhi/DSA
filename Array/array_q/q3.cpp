#include <iostream>
using namespace std;
// Longest Arithmetic subarray
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int pd = a[1] - a[0]; 
    int curr = 2;
    int ans = 2;
    for (int j = 2; j < n; j++)
    {
        if (a[j] - a[j - 1] == pd)
        {
            curr++;
        }
        else
        {
            pd = a[j] - a[j - 1];
            curr = 2;
        }
        ans = max(curr, ans);
    }
    cout << ans;

    return 0;
}