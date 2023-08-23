#include <bits/stdc++.h>
using namespace std;
// You are given an array prices where prices[i] is the price of a given stock on the ith day.
// Find the maximum profit you can achieve. You may complete at most two transactions.
// Note: You may not engage in multiple transactions simultaneously
// (i.e., you must sell the stock before you buy again).

// It is similar to last question  just here we need extra variable limit to track no of trans
// hence it will lead to *****3D DP*****
// limit is decreased by 1 either it is selled or bought (not for both of them).
int solveMem(vector<int> &prices, int idx, int buy, int limit, vector<vector<vector<int>>> &dp)
{
    if (idx == prices.size() || limit == 0)
    {
        return 0;
    }
    if (dp[idx][buy][limit] != -1)
        return dp[idx][buy][limit];
    int profit = 0;
    if (buy) // you can buy  *****prices will be subtracted while buying*****
    {
        int buyKaro = solveMem(prices, idx + 1, 0, limit, dp) - prices[idx];
        int leaveKaro = solveMem(prices, idx + 1, 1, limit, dp);
        profit = max(buyKaro, leaveKaro);
    }
    else
    {
        int sellKaro = solveMem(prices, idx + 1, 1, limit - 1, dp) + prices[idx];
        int leaveKaro = solveMem(prices, idx + 1, 0, limit, dp);
        profit = max(sellKaro, leaveKaro);
    }
    return dp[idx][buy][limit] = profit;
}
int solveTab(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));
    for (int idx = n - 1; idx >= 0; idx--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            for (int limit = 1; limit <= 2; limit++)
            {
                int profit = 0;
                if (buy) // you can buy  *****prices will be subtracted while buying*****
                {
                    int buyKaro = dp[idx + 1] [0][limit] - prices[idx];
                    int leaveKaro = dp[idx + 1][1][limit];
                    profit = max(buyKaro, leaveKaro);
                }
                else
                {
                    int sellKaro = dp[idx + 1][1][limit - 1] + prices[idx];
                    int leaveKaro = dp[idx + 1][0][limit];
                    profit = max(sellKaro, leaveKaro);
                }
                dp[idx][buy][limit] = profit;
            }
        }
    }
    return dp[0][1][2];
}
int solveSpace(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<int>>next (2, vector<int>(3, 0));
    vector<vector<int>>curr (2, vector<int>(3, 0));
    for (int idx = n - 1; idx >= 0; idx--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            for (int limit = 1; limit <= 2; limit++)
            {
                int profit = 0;
                if (buy) // you can buy  *****prices will be subtracted while buying*****
                {
                    int buyKaro = next[0][limit] - prices[idx];
                    int leaveKaro = next[1][limit];
                    profit = max(buyKaro, leaveKaro);
                }
                else
                {
                    int sellKaro = next[1][limit - 1] + prices[idx];
                    int leaveKaro =next[0][limit];
                    profit = max(sellKaro, leaveKaro);
                }
                curr[buy][limit] = profit;
            }
        }
        next=curr;
    }
    return next[1][2];
}
int maxProfit(vector<int> &prices)
{
    vector<vector<vector<int>>> dp(prices.size() + 1, vector<vector<int>>(2, vector<int>(3, -1)));
    return solveMem(prices, 0, 1, 2, dp);
}
int main()
{
    return 0;
}