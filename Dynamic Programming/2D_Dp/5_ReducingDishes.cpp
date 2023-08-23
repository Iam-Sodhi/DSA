#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
//****IMP**** ->like knapsack , simple but *****Require Sorting***** that's the catch
// A chef has collected data on the satisfaction level of his n dishes. Chef can cook any dish in 1 unit of time.
// Like-time coefficient of a dish is defined as the time taken to cook that dish including previous dishes multiplied by its satisfaction level i.e. time[i] * satisfaction[i].
// Return the maximum sum of like-time coefficient that the chef can obtain after dishes preparation.
// Dishes can be prepared in any order and the chef can discard some dishes to get this maximum value.
// satisfaction = [-1,-8,0,5,-9]
// Output: 14
// Explanation: After Removing the second and last dish, the maximum total like-time coefficient will be equal to (-1*1 + 0*2 + 5*3 = 14).
// Each dish is prepared in one unit of time.

// We will do the sorting as we need maximum satisfaction level which can be only when the highest level dish is made when time is higher
// sort(satisfaction.begin(),satisfaction.end());
int solveMem(vector<int> &satisfaction, int idx, int time, vector<vector<int>> &dp)
{
    if (idx == satisfaction.size())
        return 0;

    if (dp[idx][time] != -1)
    {
        return dp[idx][time];
    }

    int excl = solveMem(satisfaction, idx + 1, time, dp);
    int incl = (time * satisfaction[idx]) + solveMem(satisfaction, idx + 1, time + 1, dp);

    return dp[idx][time] = max(incl, excl);
}
int solveTab(vector<int> &s)
{
    int n = s.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 2, 0));
    // // B.C.
    // for (int i = 0; i < n + 1; i++)
    // {
    //     dp[n][i] = 0;
    // }
    for (int idx = n - 1; idx >= 0; idx--)
    {
        for (int time =idx+1; time >= 1; time--) //****here time=idx+1 as time can vary from 1 to total dishes taken
        {

            int excl = dp[idx+1][time];
            int incl = (time * s[idx]) + dp[idx+1][time+1];
             dp[idx][time] = max(incl, excl);
        }
    }
   return dp[0][1];
}

//possible as dp[i][t] depends on dp[i+1][t] & dp[i+1][t+1] means  i+1 row
int solveSpace(vector<int>& s){
    int n = s.size();
    vector<int> curr(n+2,0);
    vector<int> next(n+2,0);
      for (int idx = n - 1; idx >= 0; idx--)
    {
        for (int time =idx+1; time >= 1; time--) //****here time=idx+1 as time can vary from 1 to total dishes taken
        {

            int excl = next[time];
            int incl = (time * s[idx]) + next[time+1];
             curr[time] = max(incl, excl);
        }
        next=curr;
    }
   return next[1];
}
int main()
{
    //    sort(satisfaction.begin(),satisfaction.end());
    //         vector<vector<int>> dp(satisfaction.size(),vector<int>(satisfaction.size()+1,-1));
    //         return solveMem(satisfaction,0,1,dp);
    return 0;
}