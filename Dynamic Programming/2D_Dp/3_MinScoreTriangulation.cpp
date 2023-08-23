#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
//****IMP problem***** -> we see Matrix Chain Multiplication here
// You have a convex n-sided polygon where each vertex has an integer value.
// You are given an integer array values where values[i] is the value of the ith vertex (i.e., clockwise order).
// You will triangulate the polygon into n - 2 triangles. For each triangle, the value of that triangle is the product of the values of its vertices,
// and the total score of the triangulation is the sum of these values over all n - 2 triangles in the triangulation.
// Return the smallest possible total score that you can achieve with some triangulation of the polygon.

//top-down
int solveMem(vector<int> &v, int i, int j, vector<vector<int>> &dp)
{
    if (i + 1 == j)
        return 0;
    if (dp[i][j] != -1) // dp[i][j] stors the min total score which we can obtain if we have i as starting index and j as ending index
        return dp[i][j];
    int ans = INT_MAX;
    for (int k = i + 1; k < j; k++)
    {
        ans = min(ans, v[i] * v[j] * v[k] + solveMem(v, k, j, dp) + solveMem(v, i, k, dp));
    }
    return dp[i][j] = ans;
}

//bottom up
int solveTab(vector<int> &v)
{
    vector<vector<int>> dp(v.size(), vector<int>(v.size(), 0));
    int n = v.size();
    for (int i = 0; i < n; i++)  //bottom up
    {
        for (int j = i + 2; j < n; j++)  //not start from i+1 as no point in it (see Base Condition in top down approach)
        {
            int ans = INT_MAX;
            for (int k = i + 1; k < j; k++)
            {
                ans = min(ans, v[i] * v[j] * v[k] + dp[k][j] + dp[i][k]);
            }
            return dp[i][j] = ans;
        }
    }
    return dp[0][n-1];
}

//space optimization is not as dp[i][j] depends on kth row which can vary
int main()
{  // values = [1,2,3];
    return 0;
}