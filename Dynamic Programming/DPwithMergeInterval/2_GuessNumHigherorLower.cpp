#include <bits/stdc++.h>
using namespace std;
// Wording is confusing, so try to understand as the code is relativily easy
//  We are playing the Guessing Game. The game will work as follows:
//  I pick a number between 1 and n.
//  You guess a number.
//  If you guess the right number, you win the game.
//  If you guess the wrong number, then I will tell you whether the number I picked is higher or lower, and you will continue guessing.
//  Every time you guess a wrong number x, you will pay x dollars. If you run out of money, you lose the game.
//  Given a particular n, return the minimum amount of money you need to guarantee a win regardless of what number I pick.

//*****here we need to find the number form 1 to n (using loop) which will give the minimum amount of money even if it is guessed wrong and even after
// getting the the maximum number of money deducted from the picking the rest.

//dp[i][j] is the min amount of money req to win for range[i,j]
int solveMem(int start, int end, vector<vector<int>> &dp)
{
    if (start >= end)
        return 0; //  if equal then only one number is left , it is obvious that it is the required number

    if (dp[start][end] != -1)
        return dp[start][end];
    int ans = INT_MAX;
    for (int i = start; i <= end; i++)
    {
        ans = min(ans, i + max(solveMem(start, i - 1, dp), solveMem(i + 1, end, dp))); // max is bw the lower(smaller than i) range numbers and the higher range numbers(greater then i)
    }
    return dp[start][end] = ans;
}
int solveTab(int n)
{
    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

    for (int st = n; st >= 1; st--)
    {
        for (int en = st + 1; en <= n; en++)
        {

            int ans = INT_MAX;
            for (int i = st; i <= en; i++)
            {
                ans = min(ans, i + max(dp[st] [i - 1],dp[i + 1][en] )); 
            }
            dp[st][en]=ans;
        }
    }
    return dp[1][n];
}
int getMoneyAmount(int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    return solveMem(1, n, dp);
}
int main()
{
    return 0;
}