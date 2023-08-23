#include <iostream>
#include <vector>
#include<climits>
#include <algorithm>
using namespace std;
// You are given an arraylist of N integers. You are supposed to return the max sum of the subsequence with the constraints that no two elements are adjacent in the given arraylist.

// M-!
int maxSumMem(vector<int> nums, int n, vector<int> &dp)
{ // here n is the *****last index**** of the array not size
    // we will use recursion startiong from last index and then going to lower indeces
    // Base condidtion
    if (n == 0)
    {
        return nums[0];
    }
    if (n < 0)
    {
        return 0;
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }

    // At each pt, we have two choices-> either include the curr element (dec by 2 and add it) or exclude the curr element(& dec by 1)
    int incl = maxSumMem(nums, n - 2, dp) + nums[n];
    int excl = maxSumMem(nums, n - 1, dp) + 0;

    return dp[n] = max(incl, excl);
}

// Tabular M
int maxSumTab(vector<int> nums)
{
    int n = nums.size();
    vector<int> dp(n,0); // even n size if sufficient as n-1 is the last index we require
   // base condidtion
   // Note: dp[i] store the max sum we can have upto ith index (even can be made excluding the curr index element)
    dp[0] = nums[0];
    dp[1]= max(nums[0],nums[1]);
    for (int i = 2; i < n; i++)
    {
            int incl = nums[i] + dp[i - 2];
            int excl = dp[i - 1] + 0;
            dp[i] = max(incl, excl);
        
    }

    return dp[n - 1]; // here n-1
}

//Space Optimisation
int maxSumSpace(vector<int>nums){  //O(1)
    int n=nums.size();

    int prev1=0;
    int prev2=nums[0];
    for (int i = 1; i <n; i++)
    {
      int incl= nums[i] + prev1;
      int excl= prev2+ 0;
     //increment of index
      prev1=prev2;  
      prev2=max(incl,excl);
    }
    return prev2;
    
}
int main()
{
    vector<int> nums = {9, 16, 8, 2};

    int n = nums.size();

    vector<int> dp(n + 1, -1);

    cout << maxSumMem(nums, n - 1, dp) << endl; // pass the last index here
    cout << maxSumTab(nums) << endl;
    cout << maxSumSpace(nums) << endl;

    return 0;
}