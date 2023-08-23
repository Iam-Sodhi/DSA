#include <bits/stdc++.h>
using namespace std;
//******IMP Problem*****
// Given two strings text1 and text2, return the length of their longest common subsequence.
// If there is no common subsequence, return 0. For example, "ace" is a subsequence of "abcde"

int solveMem(string& a, string &b, int i, int j, vector<vector<int>> &dp)
{ //****strings passed by reference
    if (i == a.length() || j == b.length())
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];
    int ans = 0;
    if (a[i] == b[j])
        ans = 1 + solveMem(a, b, i + 1, j + 1, dp);

    else
    {
        ans = max(solveMem(a, b, i + 1, j, dp), solveMem(a, b, i, j + 1, dp));
    }
    return dp[i][j] = ans;
}
int solveTab(string a, string b)
{
    int n = a.length();
    int m = b.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0)); // or their size could be equal to smaller string size(more optimized space)

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            int ans = 0;
            if (a[i] == b[j])
                ans = 1 + dp[i + 1] [j + 1];

            else
            {
                ans = max(dp[i + 1][j], dp[i][j + 1]);
            }
            dp[i][j] = ans;
        }
    }
    return dp[0][0];
}
int solveSpace(string a, string b)
{
    int n = a.length();
    int m = b.length();
    vector<int> curr(m+1,0);
    vector<int> next(m+1,0);
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            int ans = 0;
            if (a[i] == b[j])
                ans = 1 + next [j + 1];

            else
            {
                ans = max(next[j], curr[j + 1]);
            }
            curr[j] = ans;
        }
        next=curr;
    }
    return next[0];
}

int longestCommonSubsequence(string text1, string text2)
{
    vector<vector<int>> dp(text1.length(), vector<int>(text2.length(), -1));
    return solveMem(text1, text2, 0, 0, dp);
}
int main()
{
    return 0;
}