#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//*****hard but IMP problem*****
//The fence has n posts and you have k colors. You want to paint the fence so that not more then two adjacent posts have the same color.
//Your task is to find the number of ways to do it.
// R G B B R->correct but  R R R G B->wrong



//we have two base conditions when n=1 then ans=k ( ways are equal to different colors we have)
//when n=2 then ans= k+ k(k-1)  means same color(k) + different color(k(k-1))
//This same approach of same and different color is used to solve for others
//If question asked to divide by mod then use
//  int add (int a, int b){
//  return (a%mod +b%mod)%mod;
// }
// int multiply(int a,int b){
//     return ((a%mod)*(b%mod))%mod;   //in this question do ((a%mod)*1LL*(b%mod))%mod  to prevent integer overflow
// }
//M1
int waysMem(int n,int k,vector<int>& dp){
    if (n==1)
    {
        return k;
    }
    if (n==2)
    {
        return k+ k*(k-1);
    }
    //dp[i] stores the total diff ways to paint i fences with k colors (k is const)
    if (dp[n]!=-1) 
    {
       return dp[n];
    }

    int sameColorWays= (k-1)*waysMem(n-2,k,dp); //last two color same (n-2 elements from prev and 2 same elements which can be k-1)
    int diffColorWays=(k-1)*waysMem(n-1,k,dp); // last two color of last two elements are different
    
    return dp[n]=sameColorWays+diffColorWays; 
}

//M2
int waysTab(int n,int k){
    vector<int> dp(n,0);
    dp[1]=k;
    dp[2]= k+k*(k-1);

    for (int i = 3; i <=n; i++)
    {
        int sameC=(k-1)*dp[i-2];
        int diffC=(k-1)*dp[i-1];
        dp[i]=sameC+diffC;
    }
    return dp[n];
}

//M3   as dp[i] depends on dp[i-1]& dp[i-2]
int waysSpace(int n,int k){
    int prev1=k;
    int prev2=k + k*(k-1);
    for (int i = 3; i <=n; i++)
    {
        int sameC=(k-1)*prev1;
        int diffC=(k-1)*prev2;
        prev1=prev2;
        prev2=sameC+diffC;
    }
    return prev2;
    
}
int main()
{	int n=3;
     int k=2;

     vector<int> dp(n+1,-1);
     cout<<waysMem(n,k,dp)<<endl;
     cout<<waysTab(n,k)<<endl;
     cout<<waysSpace(n,k)<<endl;
    return 0;
}