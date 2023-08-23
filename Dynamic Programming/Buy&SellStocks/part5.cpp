#include <bits/stdc++.h>
using namespace std;
// You are given an array prices where prices[i] is the price of a given stock on the ith day, 
// and an integer fee representing a transaction fee.
// Find the maximum profit you can achieve. You may complete as many transactions as you like,
//  but you need to pay the transaction fee for each transaction.
// Note:
// You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
// The transaction fee is only charged once for each stock purchase and sale.
//It is similar to Q2 just add transaction fee either while we are buying or selling
int solveSpace(vector<int>& prices, int fee){
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
                int sellKaro = next[1]  + prices[idx]-fee;
                int leaveKaro =next[0];
                profit = max(sellKaro, leaveKaro);
            }
           curr[buy] = profit;
        }
        next=curr;
    }
    return next[1];

}
int main()
{	
    return 0;
}