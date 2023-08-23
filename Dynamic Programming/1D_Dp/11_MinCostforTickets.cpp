#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
//*****IMP Problem**** ->has Classical space optimization
// You have planned some train traveling one year in advance. The days of the year in which you will travel are given as an integer array days. Each day is an integer from 1 to 365.
// Train tickets are sold in three different ways:
// a 1-day pass is sold for costs[0] dollars,
// a 7-day pass is sold for costs[1] dollars, and
// a 30-day pass is sold for costs[2] dollars.
// The passes allow that many days of consecutive travel.
// For example, if we get a 7-day pass on day 2, then we can travel for 7 days: 2, 3, 4, 5, 6, 7, and 8.
// Return the minimum number of dollars you need to travel every day in the given list of days.
 // int solveMem( vector<int>& days, vector<int>& costs,int idx,vector<int>&dp){
    //   if(idx<0)
    //   return 0;
    //  if(dp[idx]!=-1)
    //  return dp[idx];

    //  int ans=INT_MAX;
    //    ans=min(ans,costs[0]+solveMem(days,costs,idx-1,dp));
    //   int i;
    //   for( i=idx;i>=0&&days[i]>days[idx]-7;i--);
    //    ans=min(ans,costs[1]+solveMem(days,costs,i,dp));

    //   for(i=idx;i>=0&&days[i]>days[idx]-30;i--);
    //      ans=min(ans,costs[2]+solveMem(days,costs,i,dp));

    //  return dp[idx]=ans;
    // }
    int solveTab(vector<int>& days, vector<int>& costs){
      int n=days.size();
      vector<int> dp(n+1,INT_MAX);
       dp[n]=0;

       for(int k=n-1;k>=0;k--){
         dp[k]=min(dp[k],costs[0]+dp[k+1]);
         int i;
       for( i=k;i<n&&days[i]<days[k]+7;i++);

        dp[k]=min(dp[k],costs[1]+dp[i]);
        for(i=k;i<n&&days[i]<days[k]+30;i++);
        dp[k]=min(dp[k],costs[2]+dp[i]);
    
       }
       return dp[0];
     
    }
int main()
{	 vector<int> days = {1,4,6,7,8,20};
    vector<int> costs = {2,7,15};
     // vector<int> dp(days.size(),-1);
      //   return solveMem(days,costs,days.size()-1,dp);

     cout<<solveTab(days,costs);
    return 0;
}