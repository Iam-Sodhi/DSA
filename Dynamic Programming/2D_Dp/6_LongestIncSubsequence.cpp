#include <bits/stdc++.h>
using namespace std;
//***** VERY IMP***** -> in next part of this Q we will see DP with binary search to give time complexibilty of O(nlogn)

// Given an integer array nums, return the length of the longest strictly increasing subsequence
//  Input: nums = [10,9,2,5,3,7,101,18]
// Output: 4
// Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
 
//****if Q asked to find the number of longest inc subsequences , then use dp of pair<int,int> to store the length and freq & apply
//the following condition: dp[l][f]=stores a pair of {length of LIS ,  its frequency} from that index to n-1,n indexes
// if(incl.first==excl.first){ //here just add the freq & return the pair
//     return dp[curr][prev + 1]= {incl.first,incl.second+excl.second};
// }
// else if(incl.first>excl.first){
//     return dp[curr][prev + 1]=incl;
// }
// else  return dp[curr][prev + 1]=excl;
int solveMem(vector<int> &nums, int prev, int curr, vector<vector<int>> &dp) // curr refers to curr index
{                                                                            // we will increase the prev by 1  while storing in dp as prev =-1 in first case hence answer will be stored in dp[0][0]
    if (curr == nums.size())
        return 0;

    if (dp[curr][prev + 1] != -1)
        return dp[curr][prev + 1];

    int excl = solveMem(nums, prev, curr + 1, dp);
    int incl = 0;
    if (prev == -1 || nums[curr] > nums[prev])
    {
        incl = 1 + solveMem(nums, curr, curr + 1, dp); // prev becomes curr
    }

    return dp[curr][prev + 1] = max(incl, excl);
}
int solveTab(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> dp(nums.size() + 1, vector<int>(nums.size() + 1, 0));

    for (int curr = n - 1; curr >= 0; curr--)
    {
        for (int prev = curr - 1; prev >= -1; prev--)
        {
            int excl = dp[curr + 1][prev+1]; //we have added +1 to prev as while storing the value we are also inc it to avoid -ve idx
            int incl = 0;
            if (prev == -1 || nums[curr] > nums[prev])
            {
                incl = 1 + dp[curr+1][curr+1]; //****also +1 here as second wala curr  prev ke liye hai aur prev ko 1 plus krenge
            }
            dp[curr][prev+1]=max(incl,excl);
        }
    }
    return dp[0][0];
}
//possible as dp[curr][prev] depends on dp[curr+1][prev+1]& dp[curr+1][curr+1] means next row
int solveSpace(vector<int>& nums){
    int n = nums.size();
    vector<int> next(n+1,0);
    vector<int> currR(n+1,0);

    for (int curr = n - 1; curr >= 0; curr--)
    {
        for (int prev = curr - 1; prev >= -1; prev--)
        {
            int excl = next[prev+1]; //we have added +1 to prev as while storing the value we are also inc it to avoid -ve idx
            int incl = 0;
            if (prev == -1 || nums[curr] > nums[prev])
            {
                incl = 1 + next[curr+1]; //****also +1 here as second wala curr  prev ke liye hai
            }
            currR[prev+1]=max(incl,excl);
        }
        next=currR;
    }
    return next[0];
}
    int main()
    {
        //  vector<vector<int>> dp(nums.size(),vector<int>(nums.size()+1,-1));
        //      return solveMem(nums,-1,0,dp);
        return 0;
    }