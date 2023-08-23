#include <bits/stdc++.h>
using namespace std;
//****IMP**** //here we will use hashing
// we will see that tabulation approach will not give TLE but memorisation approach will give
// Given an array nums of integers, return the length of the longest arithmetic subsequence in nums

// *****first approach***** top-down

// int solve(int idx, int diff, vector<int> & nums){
//     //for backward check
//    int nextEle=nums[idx];
//    int cnt=0;
//     for (int  j = idx-1; j >=0; j--)
//     {
//         if(nextEle-nums[j]==diff){
//             cnt++;
//             nextEle=nums[j];
//         }
//     }
//     return cnt;
// }
// or we can use memorisation
int solveMem(int idx, int diff, vector<int> &nums, unordered_map<int, int> dp[])
{
    // for backward check
    if (idx == 0)
        return 0;
    if (dp[idx].count(diff))
        return dp[idx][diff];

    int ans = 0;
    for (int j = idx - 1; j >= 0; j--)
    {
        if (nums[idx] - nums[j] == diff)
        {
            ans = max(ans, 1 + solveMem(j, diff, nums, dp));
        }
    }
    return dp[idx][diff] = ans;
}

int LAS(vector<int> &nums)
{
    int n = nums.size();
    if (n <= 2)
        return n;
    int ans = 0;
    unordered_map<int, int> dp[n + 1];
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int diff = nums[j] - nums[i];
            // now its time to check if with this difference there exist alements in peeche wale array wrt nums[i];
            // ans=max(ans,2+solve(i,diff,nums));
            ans = max(ans, 2 + solveMem(i, diff, nums, dp));
        }
    }
    return ans;
}

// M-2  Tabulation approach
//bottom up approach , j will start from 0 instead of i-1
int LAS(vector<int> &nums)
{
    int n = nums.size();
    if (n <= 2)
    {
        return n;
    }
    int ans = 0;
    unordered_map<int, int> dp[n + 1]; // it is done for memorising
    // dp[index][diff]=length  i.e. the max length of AP upto that index with cd(diff)
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            int diff = nums[i] - nums[j];
            int cnt = 1; // as only ith element present till now

            // Now  check if ans is already there for  upto jth element with cd=diff
            if (dp[j].count(diff))
            {
                cnt = dp[j][diff];
            }
            // now to include the ith element , we will increase the cnt by 1 and store in it
            dp[i][diff] = 1 + cnt; // now store the lenght of AP upto ith index with cd->diff
            ans = max(ans, dp[i][diff]);
        }
    }
    return ans;
}
int main()
{
    return 0;
}