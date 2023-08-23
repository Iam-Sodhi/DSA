#include <bits/stdc++.h>
using namespace std;
// Given an integer array arr and an integer difference, return the length of the longest subsequence
// in arr which is an arithmetic sequence such that the difference between adjacent elements in the subsequence equals difference.
int longestSubsequence(vector<int> &arr, int diff)
{
    unordered_map<int, int> dp; // to store max length wrt  each index
        int ans=0;
    for (int i = 0; i < arr.size(); i++)
    {
        int prev = arr[i] - diff;
        if(dp.count(prev)){
            dp[arr[i]]=dp[prev]+1;
        }
        else{
            dp[arr[i]]=1;
        }
        ans=max(ans,dp[arr[i]]);
    }
    return ans;
}
int main()
{
    return 0;
}