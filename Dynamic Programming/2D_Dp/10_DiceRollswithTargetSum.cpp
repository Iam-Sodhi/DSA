#include <bits/stdc++.h>
using namespace std;
//****Interesting base condition****** based on distinct pattern
// You have n dice, and each die has k faces numbered from 1 to k.
// Given three integers n, k, and target, return the number of possible ways (out of the kn total ways) to roll the dice,
// so the sum of the face-up numbers equals target. Since the answer may be too large, return it modulo 109 + 7.

int mod = 1e9 + 7;
long long solveMem(int n, int k, int target, vector<vector<long long>> &dp)
{
    if (target < 0)
        return 0;
    if (target == 0 && n != 0)
        return 0;
    if (n == 0 && target != 0)
        return 0;
    if (n == 0 && target == 0)
        return 1;

    if (dp[n][target] != -1)
        return dp[n][target];
    long long ans = 0;
    for (int i = 1; i <= k; i++)
    {
        ans += (solveMem(n - 1, k, target - i, dp) % mod);
    }
    return dp[n][target] = ans;
}
long long solveTab(int n, int k, int target)
{
    vector<vector<long long>> dp(n + 1, vector<long long>(target + 1, 0));
    dp[0][0] = 1;
    for (int dice = 1; dice <= n; dice++)
    {
        for (int t = 1; t <= target; t++)
        {

            long long ans = 0;
            for (int i = 1; i <= k; i++)
            {   if(t -i>=0)
                ans += (dp[dice-1][t -i]% mod);
            }
          dp[dice][t] = ans;
        }
    }
    return dp[n][target];
}
long long solveSpace(int n, int k, int target){
    vector<long long> curr(target+1,0);
    vector<long long> prev(target+1,0);
    prev[0]=1;
        for (int dice = 1; dice <= n; dice++)
    {
        for (int t = 1; t <= target; t++)
        {

            long long ans = 0;
            for (int i = 1; i <= k; i++)
            {   if(t -i>=0)
                ans += (prev[t -i]% mod);
            }
          curr[t] = ans;
        }
        prev=curr;
    }
    return prev[target];
   

}
long long numRollsToTarget(int n, int k, int target)
{
    vector<vector<long long>> dp(n + 1, vector<long long>(target + 1, -1));
    return solveMem(n, k, target, dp) % mod;
}
int main()
{
    return 0;
}