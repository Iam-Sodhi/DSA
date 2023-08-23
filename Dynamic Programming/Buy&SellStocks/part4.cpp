#include <bits/stdc++.h>
using namespace std;
// You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.
// Find the maximum profit you can achieve.
// You may complete at most k transactions: i.e. you may buy at most k times and sell at most k times.
// Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

//It is similar to last question just instead of 2 there is k limit.
//we can also avoid using 3D dp by using variable operation instead of buy&limit like last question.
// if(operation%2==0) then we can buy or leave
// if(operation%2==1) then we can sell  or leave
//Base condition will be like( idx==n || operation= 2*K) //*****  2*k=total operation (k is one transaction)

//here we will use last question code
int solveSpace(vector<int> &prices,int k)
{
    int n = prices.size();
    vector<vector<int>>next (2, vector<int>(k+1, 0));
    vector<vector<int>>curr (2, vector<int>(k+1, 0));
    for (int idx = n - 1; idx >= 0; idx--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            for (int limit = 1; limit <= k; limit++)
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
    return next[1][k];
}
int maxProfit(int k, vector<int>& prices) {
        return solveSpace(prices,k);
    }

int main()
{	
    return 0;
}