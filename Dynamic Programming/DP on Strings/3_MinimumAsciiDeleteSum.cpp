#include <bits/stdc++.h>
using namespace std;
// Given two strings s1 and s2,
// return the lowest ASCII sum of deleted characters to make two strings equal.
// s1 = "sea", s2 = "eat"
// Output: 231
// Explanation: Deleting "s" from "sea" adds the ASCII value of "s" (115) to the sum.
// Deleting "t" from "eat" adds 116 to the sum.
// At the end, both strings are equal, and 115 + 116 = 231 is the minimum sum possible to achieve this.

int solveMem(string& a, string& b, int i, int j, vector<vector<int>> &dp)
{ //****strings passed by reference
    if (i == a.length() && j == b.length())
        return 0;
    if (i==a.length() ){
        int sum= 0;
        for(int k=j;k<b.length();k++) sum+=b[k];
        return sum;
    }
     if (j==b.length() ){
        int sum= 0;
        for(int k=i;k<a.length();k++) sum+=a[k];
        return sum;
    }

    if (dp[i][j] != -1)
        return dp[i][j];
    int ans = 1e5;
    if (a[i] == b[j])
        ans = solveMem(a, b, i + 1, j + 1, dp);

    
    else{
        ans = min(a[i]+solveMem(a, b, i + 1, j, dp), b[j]+solveMem(a, b, i, j + 1, dp));
    }
    return dp[i][j] =ans;
}
    int minimumDeleteSum(string s1, string s2) {
        vector<vector<int>> dp(s1.length(), vector<int>(s2.length(), -1));
    return solveMem(s1, s2, 0, 0, dp);
    }
int main()
{	
    return 0;
}