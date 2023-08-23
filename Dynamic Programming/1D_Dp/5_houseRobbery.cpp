#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//Similar to 4th question
//ou are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed,
// the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.
//*****All houses  are arranged in a circle *****
//Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

//Taken from prev question 
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
{	 //Only catch is that the first and last elements can't be taken together as houses are in circle(will become adj otherwise)
     //So we will just make two arrays one including one of them at a time
     vector<int> nums={2,3,2};
     int n=nums.size();
    
    vector<int> first,second;
     for (int i = 0; i < n; i++)
     {
        if(i!=0)
        first.push_back(nums[i]);

        if(i!=n-1)
        second.push_back(nums[i]);
     }
     

     if (n==1) //here we can rob the only house present 
     {
        cout<<nums[0]<<endl;
     }
     else //return the max from what we get from first and second array
     {
        cout<<max(maxSumSpace(first),maxSumSpace(second));
     }
     
     
    return 0;
}