#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;
//*****IMP problem****
// You are given an array of N distict integers and an integer X representing the target sum.
// You have to tell the minimum no of elements you have to take to reach the target sum X
// NOTE: You have infinite no of elements of each type

// MEMORY method
int minElements(vector<int> &num, int x, vector<int> &dp)
{
    // base conditions
    if (x == 0)
    {
        return 0; // no coin is need to make sum =0
    }
    if (x < 0)
    {
        return INT_MAX; // as we need to find min , lets make it INT_MAX
    }
    if (dp[x] != -1)
    {
        return dp[x];
    }

    int mini = INT_MAX;
    for (int i = 0; i < num.size(); i++)
    {
        int ans = minElements(num, x - num[i], dp);
        if (ans != INT_MAX)
        {
            mini = min(mini, 1 + ans); // otherwise 1 +ans will give integer overflow
        }
    }
    return dp[x] = mini;
}

// Tabulation Method -> bottom to top  have same time complexibilty
int minElements2(vector<int> &num, int x)
{
    vector<int> dp(x + 1 , INT_MAX); //here make them equal to INT_MAX
    dp[0] = 0; // no coin needed to make sum=0

    for (int i = 1; i <= x; i++) // solve the min coins taken to form every amount figure from 1 to x
    {
        for (int j = 0; j < num.size(); j++)
        {
            if (i - num[j] >= 0 && dp[i-num[j]]!=INT_MAX) //dp[i-num[j]]!=INT_MAX to prevent integer overflow
            {
                dp[i] = min(dp[i], 1 + dp[i - num[j]]);
            }
        }
    }
    if (dp[x]==INT_MAX) 
    {
     return -1;
    }
    return dp[x];
}
int main()
{
    int x = 7;
    vector<int> num = {1, 2, 3};

    vector<int> dp(x + 1, -1); // here size is x+1
    int ans = minElements(num, x, dp);
    if (ans != INT_MAX)
    {
        cout << ans<<endl;
    }

   cout<<minElements2(num,x)<<endl;
    return 0;
}