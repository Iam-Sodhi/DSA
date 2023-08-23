#include <iostream>
#include <queue>
using namespace std;
// Given an array , find the largest Kth subarray
// We are gonna use min heap to find the largest Kth subarray (or max heap to find the smallest Kth subarray)
int KthLargestSubarray(int a[], int n, int k)
{
    priority_queue<int, vector<int>, greater<int>> mini; // STL For min heap
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += a[j];
            if (mini.size() < k) // here not <= k as size is q in first case sum is pushed later not before
            {
                mini.push(sum);
            }
            else
            {
                if (mini.top() < sum) // will make the space complexibility to O(k)
                {
                    mini.pop();
                    mini.push(sum);
                }
            }
        }
    }
    return mini.top();
}
int main()
{
    int a[] = {1, 4, 8, 16, 9, 3, 10};
    int n = sizeof(a) / sizeof(a[0]);
    int k = 3;
    int ans = KthLargestSubarray(a, n, k);
    cout << "The Kth largest subarray is " <<ans<< endl;
    return 0;
}