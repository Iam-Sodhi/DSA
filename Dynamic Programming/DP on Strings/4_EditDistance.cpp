#include <bits/stdc++.h>
using namespace std;
//******IMP Problem***** it's optimal solution is difficult & tricky ->see carefully
// Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.
// You have the following three operations permitted on a word:
// Insert a character , Delete a character , Replace a character
// word1 = "horse", word2 = "ros" , Output: 3
// Explanation:
// horse -> rorse (replace 'h' with 'r')
// rorse -> rose (remove 'r') , rose -> ros (remove 'e')
int solveMem(string &word1, string &word2, int i, int j, vector<vector<int>> &dp)
{
    if (i == word1.size())
        return word2.size() - j; // as all remaining characters of word2 need to be inserted
    if (j == word2.size())
        return word1.size() - i; // they need to be deleted

    if (dp[i][j] != -1)
        return dp[i][j];

    int ans = INT_MAX;
    if (word1[i] == word2[j])
    { // no operation neede
        ans = min(ans, solveMem(word1, word2, i + 1, j + 1, dp));
    }
    else
    {
        // insert
        int insert = 1 + solveMem(word1, word2, i, j + 1, dp);
        // delete
        int deletion = 1 + solveMem(word1, word2, i + 1, j, dp);
        int replace = 1 + solveMem(word1, word2, i + 1, j + 1, dp);
        ans = min(insert, min(deletion, replace));
    }
    return dp[i][j] = ans;
}
int solveTab(string a, string b)
{
    int n = a.size();
    int m = b.size();
    vector<vector<int>> dp(n + 1, vector<int>(m, 0));
    for (int j = 0; j < m; j++)
    {
        dp[n][j] = m - j;
    }
    for (int i = 0; i < n; i++)
    {
        dp[i][m] = n - i;
    }

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            int ans = INT_MAX;
            if (a[i] ==b[j])
            { // no operation neede
                ans = min(ans, dp[i + 1] [j + 1]);
            }
            else
            {
                // insert
                int insert = 1 + dp[i][j + 1];
                // delete
                int deletion = 1 + dp[i + 1][j];
                int replace = 1 + dp[i + 1][j + 1];
                ans = min(insert, min(deletion, replace));
            }
            dp[i][j] = ans;
        }
    }
    return dp[0][0];
}
int solveSpace(string a, string b)
{
    int n = a.size();
    int m = b.size();
    vector<int> curr(m+1,0);
    vector<int> next(m+1,0);
    for (int j = 0; j < m; j++) // it is for last row . i.e. the next row
    {
        next[j] = m - j;
    }
   // 2nd base case will be tackeled inside
    for (int i = n - 1; i >= 0; i--)
    {    curr[m]=n-i; //here we have done the base condition when j=b.length()
        for (int j = m - 1; j >= 0; j--)
        {
            int ans = INT_MAX;
            if (a[i] ==b[j])
            { // no operation neede
                ans = min(ans, next [j + 1]);
            }
            else
            {
                // insert
                int insert = 1 + curr[j + 1];
                // delete
                int deletion = 1 +next[j];
                int replace = 1 +next[j + 1];
                ans = min(insert, min(deletion, replace));
            }
           curr[j] = ans;
        }
        next=curr;
    }
    return next[0];
}
int minDistance(string word1, string word2)
{
    vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size(), -1));
    return solveMem(word1, word2, 0, 0, dp);
}
int main()
{
    return 0;
}