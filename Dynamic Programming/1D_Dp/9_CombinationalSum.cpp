#include <iostream>
#include <vector>
#include <algorithm>
#include<climits>
using namespace std;
// Given an array of distinct integers nums and a target integer target, return the number of possible combinations that add up to target

int waysMem(vector<int>&nums,int t,vector<int>& dp){
     if (t==0)
     {
        return 1;
     }
     if (t<0)
     {
        return 0;
     }
     if(dp[t]!=-1)
     return dp[t];
     int ans=0;
     for (int i = 0; i < nums.size(); i++)
     {
         ans+=waysMem(nums,t-nums[i],dp);
     }
     return dp[t]=ans;
}

int waysTab(vector<int>&nums,int t){
    vector<int> dp(t+1,0);
    dp[0]=1;

    for (int i = 1; i <=t; i++)
    {   
         for (int j = 0; j < nums.size(); j++)
         {  if(i-nums[j]>=0)
            dp[i]+=dp[i-nums[j]];
         }
         
    }
    return dp[t];
}
// as dp[i] depends on dp[i-nums[j]]  we can't determine nums[j] hence space optimisation not possible
int main()
{
    vector<int> nums = {1, 2, 3};
    int target = 4;
  
   vector<int> dp(target+1,-1);
    cout<<waysMem(nums,target,dp)<<endl;
    cout<<waysTab(nums,target)<<endl;
    return 0;
}