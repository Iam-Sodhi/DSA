#include <bits/stdc++.h>
using namespace std;
//****IMP***** 
// There is a pizza with 3n slices of varying size, you and your friends will take slices of pizza as follows:
// You will pick any pizza slice.
// Your friend Alice will pick the next slice in the anti-clockwise direction of your pick.
// Your friend Bob will pick the next slice in the clockwise direction of your pick.
// Repeat until there are no more slices of pizzas.
// Given an integer array slices that represent the sizes of the pizza slices in a clockwise direction, return the maximum possible sum of slice sizes that you can pick.

//this q is little bit like house robbery in circular  as if we can eat only one from the first idx or last idx pizza not both together.
//out of 3n slices, you will get n slices ->common sense ****hence there is a condition that you have to pick exactly n slices not more than or less than that
//hence we can't use the house robbery method as there it is we do n't have that condition 
//We will another variable to store the slices(that are to be ate) which we have to eat hence become 2D DP
//here we will use 2 DP  instead of 2 arrays

int solveMem(vector<int>& slices, int stIdx, int endIdx, int k, vector<vector<int> >&dp){
    if(stIdx>endIdx || k==0){
        return 0;
    }
    
    if(dp[stIdx][k]!=-1){
        return dp[stIdx][k];
    }
    int incl= slices[stIdx]+ solveMem(slices,stIdx+2,endIdx,k-1,dp);
    int excl=solveMem(slices,stIdx+1,endIdx,k,dp);

    return dp[stIdx][k]=max(incl,excl);
}
int solveTab(vector<int>& slices){
    int n=slices.size();
         if(n==0) return 0;
     vector<vector<int>> dp1(n+2,vector<int>((n/3)+1,0)); //n+2 just to be safe to avoid bufferoverflow
     vector<vector<int>> dp2(n+2,vector<int>((n/3)+1,0));
  // we will use 2 separate loops to solve for dp1 & dp2 with their own st and end Idx conditions
     for (int st =n-2; st >=0; st--)
     {
        for (int k = 1; k <=n/3; k++)
        {
            int incl= slices[st]+ dp1[st+2][k-1];
            int excl= dp1[st+1][k];
            dp1[st][k]=max(incl,excl);
        }
     }
     for (int st =n-1; st >=1; st--) //here***** diff st and end Idx see carefully*****
     {
        for (int k = 1; k <=n/3; k++)
        {
            int incl= slices[st]+ dp2[st+2][k-1];
            int excl= dp2[st+1][k];
            dp2[st][k]=max(incl,excl);
        }
     }
     
   return max(dp1[0][n/3],dp2[1][n/3]);
}
//possible as dp[st][] depends on other two rows [st+1][] & [st+2][]
int solveSpace(vector<int>& slices){
    int n=slices.size();
         if(n==0) return 0;
     vector<int> curr1((n/3)+1,0);
     vector<int> curr2((n/3)+1,0);
     vector<int> next1((n/3)+1,0);
     vector<int> next2((n/3)+1,0);
     vector<int> prev1((n/3)+1,0);
     vector<int> prev2((n/3)+1,0);
     for (int st =n-2; st >=0; st--)
     {
        for (int k = 1; k <=n/3; k++)
        {
            int incl= slices[st]+ next1[k-1];
            int excl= curr1[k];
            prev1[k]=max(incl,excl);
        }
        next1=curr1;
        curr1=prev1;
     }
     for (int st =n-1; st >=1; st--) //here***** diff st and end Idx see carefully*****
     {
        for (int k = 1; k <=n/3; k++)
        {
            int incl= slices[st]+ next2[k-1];
            int excl= curr2[k];
            prev2[k]=max(incl,excl);
        }
        next2=curr2;
        curr2=prev2;
     }
     
   return max(curr1[n/3],curr2[n/3]);
}
  int maxSizeSlices(vector<int>& slices) {
 
     int n=slices.size();
     if(n==0) return 0;
    vector<vector<int>> dp1(n+1,vector<int>((n/3)+1,-1));
    vector<vector<int>> dp2(n+1,vector<int>((n/3)+1,-1));

    int ans= max(solveMem(slices,0,n-2,n/3,dp1), solveMem(slices,1,n-1,n/3,dp2)); //here see the st and en idx
}
int main()
{	
    return 0;
}