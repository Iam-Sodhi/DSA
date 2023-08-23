#include <iostream>
#include <vector>
#include <algorithm>
#include<math.h>
#include <climits>
using namespace std;
//find the min no of squares of any number that sums to N.
//e.g 100 is exprssed as 10*10 or (5*5+5*5+5*5+5*5) but our answer shoul be 1 as (10*10) is min no 
 
 int minSquaresMem(int n, vector<int>&dp){
    if(n==0){
        return 0;
    }
    if(dp[n]!=-1)
    return dp[n];

    int ans=n; // as n can be the max squares it 
    for(int i=1; i<=sqrt(n);i++){
      ans=min(ans,1+minSquaresMem(n-(i*i),dp));
    }
    return dp[n]=ans;
 }
 int minSquaresTab(int n){
    vector<int> dp(n+1,INT_MAX);

    dp[0]=0;

    for (int i = 1; i <=n; i++)
    {
        for (int j = 1; j <=sqrt(i); j++)
        {   if(i-(j*j)>=0)
            dp[i]=min(dp[i],1+dp[i-(j*j)]);
        }
        
    }
    return dp[n];
 }
 //can't have space optimization
int main()
{	 int n=7;

     vector<int>dp(n+1,-1);
     cout<<minSquaresMem(n,dp)<<endl;
     cout<<minSquaresTab(n)<<endl;

    return 0;
}