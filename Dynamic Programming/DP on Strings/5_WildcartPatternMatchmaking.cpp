#include <bits/stdc++.h>
using namespace std;
//*****IMP Problem***** -> see the base conditions & other conditions carefully
// Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:
// '?' Matches any single character.
// '*' Matches any sequence of characters (including the empty sequence).
// The matching should cover the entire input string (not partial).
// Input: s = "cb", p = "?a"
// Output: false
// Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.

bool solveMem(string &s, string &p, int i, int j, vector<vector<int>> &dp)
{                         // we index from 1 to make it easy to have solveTab
    if (i == 0 && j == 0) // here 0 is not the first index but means string is now empty (indexing from 1)
        return true;      // means
    if (i > 0 && j == 0)
        return false; // means pattern(p) string has ended but string s is still there ( hence unsuccessful)
    if (i == 0 && j > 0)
    { // here we have to check that that the remaining character('s) in the pattern string does n't have only '*' characters
      // with only '*' remaining , it is successful ( as '*' can also be repalced with empty string)
        for (int k = j; k > 0; k--)
        {
            if (p[k - 1] != '*') // means there is some other character also present in p
                return false;
        }
        return true;
    }

    if (dp[i][j] != -1)
        return dp[i][j];

    if (s[i - 1] == p[j - 1] || p[j - 1] == '?')
    { // means that character can be replaced
        return dp[i][j] = solveMem(s, p, i - 1, j - 1, dp);
    }
    else if (p[j - 1] == '*') //*****here 2 choices are there one to replace with empty string(j-1) or situation when * is replaced by '*c' where c is the s[i-1]
    {
        return dp[i][j] = solveMem(s, p, i, j - 1, dp) || solveMem(s, p, i - 1, j, dp); // in 1st cond only j is reduced as '*' is repaced by ''->empty string
        // in other condition  only i is reduced as that and j will remain on '*' as it was before
    }
    else
    {
        return dp[i][j] = false;
    }
}

bool solveTab(string &s, string &p)
{
    int n = s.size();
    int m = p.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, false));
    dp[0][0] = true;
    // for second condition there is no need as they are already false
    for (int j = 1; j <= m; j++)
    {
        bool flag = true;
        for (int k = 1; k <= j; k++)
        {
            if (p[k - 1] != '*') // means there is some other character also present in p
            {
                flag = false;
                break;
            }
        }
        dp[0][j] = flag;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s[i - 1] == p[j - 1] || p[j - 1] == '?')
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else if (p[j - 1] == '*')
            {
                dp[i][j] = (dp[i][j - 1] || dp[i - 1][j]);
            }
            else
            {
                dp[i][j] = false;
            }
        }
    }
    return dp[n][m];
}
bool solveSpace(string &s, string &p)
{
    int n = s.size();
    int m = p.size();
    vector<int> prev(m+1,false);
    vector<int> curr(m+1,false);
    prev[0] = true;
    // for second condition there is no need as they are already false
    for (int j = 1; j <= m; j++)
    {
        bool flag = true;
        for (int k = 1; k <= j; k++)
        {
            if (p[k - 1] != '*') // means there is some other character also present in p
            {
                flag = false;
                break;
            }
        }
        prev[j] = flag;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s[i - 1] == p[j - 1] || p[j - 1] == '?')
            {
                curr[j] = prev[j - 1];
            }
            else if (p[j - 1] == '*')
            {
                curr[j] = (curr[j - 1] || prev[j]);
            }
            else
            {
                curr[j] = false;
            }
        }
        prev=curr;
    }
    return prev[m];
}
bool isMatch(string s, string p)
{
    vector<vector<int>> dp(s.size() + 1, vector<int>(p.size() + 1, -1));
    solveMem(s, p, s.size(), p.size(), dp);
}
int main()
{
    return 0;
}