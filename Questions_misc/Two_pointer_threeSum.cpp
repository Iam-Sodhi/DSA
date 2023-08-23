#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// Find if there exists three numbers in the given array whose sum is equal to the given value

// // Brute force
// bool bruteforce(vector<int> a, int target)
// {
//     int n = a.size();
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = i + 1; j < n; j++)
//         {
//             for (int k = j + 1; k < n; k++) // time complexibility O(n^3);
//             {
//                 if (a[i] + a[j] + a[k] == target)
//                 {
//                     return true;
//                 }
//             }
//         }
//     }
//     return false;
// }

// using better aproach -> where first the array is sorted then two sum two pointer approach is tried
bool threeSum_twoptr(vector<int> a, int target)
{
    int n = a.size();
    sort(a.begin(), a.end()); // O(nlogn)

    for (int i = 0; i < n; i++)
    {
        int l = i + 1, h = n - 1;
        while (l < h)
        {
            if (target == a[i] + a[l] + a[h])
            {
                cout << endl
                     << a[i] << " " << a[l] << " " << a[h] << endl; //*****overall time complexibitly is O(n^2)*****
                                                                    // O(nlogn) for sorting and O(n^2) for two sum ---> O(n^2)
                return true;
            }

            else if (target > a[i] + a[l] + a[h])
            {
                l++;
            }
            else
            {
                h--;
            }
        }
    }
    return false;
}
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &i : a)
    {
        cin >> i;
    }
    cout << threeSum_twoptr(a, k);
    return 0;
}