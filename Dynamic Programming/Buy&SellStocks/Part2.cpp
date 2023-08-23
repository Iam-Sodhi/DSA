#include <bits/stdc++.h>
using namespace std;
// You are given an integer array prices where prices[i] is the price of a given stock on the ith day.
// On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time.
// However, you can buy it then immediately sell it on the same day.
// Find and return the maximum profit you can achieve.

// Here you can have transactions multiple times just *****after buying you must sell & after sell you must buy*****(at most one share at any time)
//  here we will use a buy variable (that if buy=1 then only you can buy otherwise you may sell or leave it alone)
int solveMem(vector<int> &prices, int idx, int buy, vector<vector<int>> &dp)
{
    if (idx == prices.size())
    {
        return 0;
    }
    if (dp[idx][buy] != -1)
        return dp[idx][buy];
    int profit = 0;
    if (buy) // you can buy  *****prices will be subtracted while buying*****
    {
        int buyKaro = solveMem(prices, idx + 1, 0, dp) - prices[idx];
        int leaveKaro = solveMem(prices, idx + 1, 1, dp);
        profit = max(buyKaro, leaveKaro);
    }
    else
    {
        int sellKaro = solveMem(prices, idx + 1, 1, dp) + prices[idx];
        int leaveKaro = solveMem(prices, idx + 1, 0, dp);
        profit = max(sellKaro, leaveKaro);
    }
    return dp[idx][buy] = profit;
}
int solveTab(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));

    for (int idx = n - 1; idx >= 0; idx--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            int profit = 0;
            if (buy) // you can buy  *****prices will be subtracted while buying*****
            {
                int buyKaro = dp[idx+1][0] - prices[idx];
                int leaveKaro = dp[idx + 1][1] ;
                profit = max(buyKaro, leaveKaro);
            }
            else
            {
                int sellKaro = dp[idx + 1][1]  + prices[idx];
                int leaveKaro = dp[idx + 1][0];
                profit = max(sellKaro, leaveKaro);
            }
            dp[idx][buy] = profit;
        }
    }
    return dp[0][1];
}
int solveSpace(vector<int>& prices){
    int n=prices.size();
    vector<int> curr(2,0);
    vector<int> next(2,0);
     for (int idx = n - 1; idx >= 0; idx--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            int profit = 0;
            if (buy) // you can buy  *****prices will be subtracted while buying*****
            {
                int buyKaro = next[0] - prices[idx];
                int leaveKaro = next[1] ;
                profit = max(buyKaro, leaveKaro);
            }
            else
            {
                int sellKaro = next[1]  + prices[idx];
                int leaveKaro =next[0];
                profit = max(sellKaro, leaveKaro);
            }
           curr[buy] = profit;
        }
        next=curr;
    }
    return next[1];

}
int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<int>> dp(n + 1, vector<int>(2, -1));
    return solveMem(prices, 0, 1, dp);
}
int main()
{
    return 0;
}