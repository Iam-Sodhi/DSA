#include <bits/stdc++.h>
using namespace std;
// Also based on distingct pattern
// Given an integer array nums, return true if you can partition the array into
// two subsets such that the sum of the elements in both subsets is equal or false otherwise.
bool solveMem(vector<int> &nums, int idx, int target, vector<vector<int>> &dp)
{
    if (idx == nums.size())
        return false; // or 0
    if (target < 0)
        return false;
    if (target == 0)
        return true; // or 1
    if (dp[idx][target] != -1)
        return dp[idx][target];

    bool excl = solveMem(nums, idx + 1, target, dp);
    bool incl = solveMem(nums, idx + 1, target - nums[idx], dp);

    return dp[idx][target] = (excl || incl);
}
bool solveTab(vector<int> &nums, int totalSum)
{
    vector<vector<int>> dp(nums.size()+1, vector<int>((totalSum / 2) + 1, 0));
    for (int i = 0; i <=nums.size(); i++)
    {
        dp[i][0] = true;
    }
    for (int idx = nums.size() - 1; idx >= 0; idx--)
    {
        for (int target = 0; target <= totalSum / 2; target++)
        {
            bool excl = dp[idx + 1][target];
            bool incl = 0;
            if (target - nums[idx] >= 0)
                incl = dp[idx + 1][target - nums[idx]];

            dp[idx][target] = (excl || incl);
        }
    }
    return dp[0][totalSum / 2];
}
bool solveSpace(vector<int> &nums, int totalSum)
{
    vector<int> curr((totalSum / 2)+1,0);
    vector<int> next((totalSum / 2)+1,0);
    next[0]=true;
    for (int idx = nums.size() - 1; idx >= 0; idx--)
    {
        for (int target = 0; target <= totalSum / 2; target++)
        {
            bool excl = next[target];
            bool incl = 0;
            if (target - nums[idx] >= 0)
                incl = next[target - nums[idx]];

            curr[target] = (excl || incl);
        }
        next=curr;
    }
    return next[totalSum / 2];
}
bool canPartition(vector<int> &nums)
{
    int sum = 0;
    for (auto &i : nums)
    {
        sum += i;
    }

    if (sum & 1)
        return false; // if odd
    // now if even we just need to find a subset of target sum= sum/2. then its true

    else
    {
        vector<vector<int>> dp(nums.size(), vector<int>((sum / 2) + 1, -1));
        return solveMem(nums, 0, sum / 2, dp);
    }
}
int main()
{
    return 0;
}