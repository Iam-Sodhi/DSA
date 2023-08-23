#include <bits/stdc++.h>
using namespace std;
// Given an array arr of positive integers, consider all binary trees such that:
// Each node has either 0 or 2 children;
// The values of arr correspond to the values of each leaf in an in-order traversal of the tree.
// The value of each non-leaf node is equal to the product of the largest leaf value in its left and right subtree, respectively.
// Among all possible binary trees considered, return the smallest possible sum of the values of each non-leaf node. It is guaranteed this sum fits into a 32-bit integer.
// A node is a leaf if and only if it has zero children.

//*****here don't overthink to try making a tree, instead use the simple solution
// Firstly divide the arr into two intervals , one for left subtree and one for right subtree , from this intervals find the maximum from each of them &
// by multiplying them you will get the topmost root node of the tree formed bythe product of the largest leaf value in its left and right subtree.
// similary we we will take first interval as the range and divide it into two intervals , which will give another non-leaf node which will be added.
// Repeat this process until start ==end as then only one leaf node will be left
int solveMem(vector<int> &arr, int start, int end, map<pair<int, int>, int> &m, vector<vector<int>> &dp)
{
    if (start == end)
        return 0; // as it means only one leaf node left , we can't have any parent(non-leaf) from only one leaf node
    if (dp[start][end] != -1)
        return dp[start][end];

    int ans = INT_MAX;
    for (int i = start; i < end; i++) // i< end means i< n-1 not equal as then no element in right interval(also m[{n-1,_}] is not defined in map)
    {
        ans = min(ans, m[{start, i}] * m[{i + 1, end}] + solveMem(arr, start, i, m, dp) + solveMem(arr, i + 1, end, m, dp));
    }
    return dp[start][end] = ans;
}
int solveTab(vector<int> &arr, map<pair<int, int>, int> m)
{
    int n = arr.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int start = n - 1; start >= 0; start--)
    {
        for (int end = start + 1; end <= n - 1; end++) // here we have avoided the condtion when start==end;
        {
            int ans = INT_MAX;
            for (int i = start; i < end; i++)
            {
                ans = min(ans, m[{start, i}] * m[{i + 1, end}] + dp[start][i] + dp[i + 1][end]);
            }
            dp[start][end] = ans;
        }
    }
    return dp[0][n-1];
}
int mctFromLeafValues(vector<int> &arr)
{
    int n = arr.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    // lets find the maximum number in diff intervals
    map<pair<int, int>, int> m;
    for (int i = 0; i < n; i++)
    {
        m[{i, i}] = arr[i];
        for (int j = i + 1; j < n; j++)
        {
            m[{i, j}] = max(arr[j], m[{i, j - 1}]);
        }
    }

    return solveMem(arr, 0, n - 1, m, dp);
}
int main()
{
    return 0;
}