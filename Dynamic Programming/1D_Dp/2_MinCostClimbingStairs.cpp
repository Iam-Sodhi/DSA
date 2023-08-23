#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// You are given an integer array cost where cost[i] is the cost of ith step on a staircase.
// Once you pay the cost, YOU can either climb one or two steps. You can either start from step with index 0, or the step with index 1.
// Return the minimum cost to reach the top of the floor

//*****M-1***** top to bottom
int solve(int n, vector<int> cost, vector<int> dp)
{

    if (n == 0)
    {
        return cost[0];
    }
    if (n == 1)
    {
        return cost[1];
    }

    if (dp[n] != -1)
    {
        return dp[n];
    }

    // you can jump to higest step(h) either from h-1 or h-2

    dp[n] = cost[n] + min(dp[n - 1], dp[n - 2]);

    return dp[n];
}
int MinCost(vector<int> cost)
{
    int n = cost.size(); // here n represents the top most step(as no need to jump from there) which is not in indexing

    vector<int> dp(n + 1, -1);                                     // it store the min cost it takes to be there and also jump from there
    int ans = min(solve(n - 1, cost, dp), solve(n - 2, cost, dp)); // here cost is not added as we don't jump from the peak step
    return ans;
}

// M-2****-> bottom to up
int MinCost2(vector<int> cost)
{
    int n = cost.size(); // here n is the peak step
    // we can jump there from n-1 or n-2 th steps
    vector<int> dp(n + 1);
    // Base condition
    dp[0] = cost[0];
    dp[1] = cost[1];
    for (int i = 2; i < n; i++) // here <n as n is not in the cost indices
    {
        dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
    }
    return min(dp[n - 1], dp[n - 2]);
}

// M-3****-> Space optimization
int MinCost3(vector<int> cost)
{
    int n = cost.size(); // here n is the peak step
    int dp1 = cost[0];
    int dp2 = cost[1];
    for (int i = 2; i < n; i++)
    {
        int t = cost[i] + min(dp1, dp2);
        int dp1 = dp2;
        int dp2 = t;
    }
    return dp2;
}
int main()
{
    vector<int> cost = {10, 15, 20}; // if there are like n steps , then cost is given for n-1 indices as starts from 0

    cout << MinCost(cost) << endl;
    cout << MinCost2(cost) << endl;
    cout << MinCost3(cost) << endl;

    return 0;
}