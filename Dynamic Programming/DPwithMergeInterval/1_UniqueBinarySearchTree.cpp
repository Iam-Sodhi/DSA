#include <bits/stdc++.h>
using namespace std;
//Given an integer n, return the number of structurally unique BST's (binary search trees) which has exactly n nodes of unique values from 1 to n.
 
//*****This question can be solved if you only know how to print catalan series*****
//*****Here the answer depends on the *****number of nodes not value of them*****
//Also remember  nodes have unique values (hence there will be no duplicates)
int solveMem(int n,vector<int> dp){
   if(n<=1) return 1;

    if(dp[n]!=-1) return dp[n]; //dp[n] stores the no of unique BSt's which have n nodes

   //loop over every number from 1 to n and using it as root node solve for other nodes ( for left side -> n=i-1 && for right side -> n=n-i)
   int ans=0;
   for(int i=1;i<=n;i++){
    ans+= solveMem(i-1,dp)* solveMem(n-i,dp);
   }
   return dp[n]=ans;
}

//Tabulaion 
int solveTab(int n){
    vector<int> dp(n+1,0);
    dp[0]=dp[1]=1;

    for(int num=2;num<=n;num++){
        
        for (int i = 1; i <=num; i++)
        {
            dp[i]+=dp[i-1]*dp[n-i];
        }
    }
    return dp[n];
}

//optimized approach is the one where we need to just print the catalan series as 1->1, 2->2,3->5, 4->14 .....
//this is also the answer for given number of nodes

 int numTrees(int n) {
        vector<int> dp(n+1,-1);
        return solveMem(n,dp);
    }
int main()
{	
    return 0;
}