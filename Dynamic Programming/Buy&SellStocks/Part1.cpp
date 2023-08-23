#include <bits/stdc++.h>
using namespace std;
// You are given an array prices where prices[i] is the price of a given stock on the ith day.
// You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
// Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

//The idea behind solving this problem is that first choose a day to sell from i=1(not =0 as we need to buy before it) to n-1 and find the  minimum price day from i=0 to day when are we going to sell the stock.
//Then find the diff bw them and do this on different days and your answer will be the maximum difference you will get.

 int maxProfit(vector<int>& prices) {
        
        int n=prices.size();
        int ans=0; // not INT_MAx as we need to return 0 in case no transaction possible ( or diff bw sell and buy is negative ->loss)
        int mini=prices[0];
        for (int  i = 1; i <n; i++)
        {
            int diff=prices[i]-mini;
            ans=max(ans,diff);
            mini=min(mini,prices[i]);
        }
        return ans;
    }
int main()
{	
    return 0;
}