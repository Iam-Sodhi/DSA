#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//*****IMP problem****
//A dearrangement is a permutation of 'N' elements, such that no elements appears in its original position.
//e.g. dearrangement of 0,1,2,3 is  2,3,1 0
//Given a number 'n', find the total number of dearangements possible of a set of n elements

//M-1
int countDearangements(int n,vector<int>& dp){
    //base condition
    if (n==1)
    {
        return 0; 
    }
    if (n==2)
    {
        return 1;
    }
    if (dp[n]!=-1)
    {
        return dp[n];
    }
    // now one element can be replace by other n-1 elements 
    // and even there comes two ways-> one in which both of selected elements swap each other and other where only one element takes the position of the other element
    int ans= (n-1)*((countDearangements(n-1,dp))+countDearangements(n-2,dp));
    return dp[n]=ans;
}
//M-2
int countDearangementsTab(int n){
    vector<int> dp(n+1,0);
    dp[1]=0;
    dp[2]=1;
    //dp[i] stores the max dearangements we can have for i size

    for (int i = 3; i <=n; i++)
    {
        dp[i]= (i-1)*(dp[i-1]+dp[i-2]);
    }
    return dp[n];
}

//M-3  as dp[i] depends on the dp[i-1] & dp[i-2]
int countDearangementsSpace(int n){
     int prev1=0;
     int prev2=1;

     for (int i = 3; i <=n; i++)
     {
        int ans=(i-1)*(prev1+prev2);
        prev1=prev2;
        prev2=ans;
     }
     return prev2;
}
int main()
{	int n=3;   
    
    vector<int> dp(n+1,-1);
    cout<<countDearangements(n,dp)<<endl;
    cout<<countDearangementsTab(n)<<endl;
    cout<<countDearangementsSpace(n)<<endl;
    return 0;
}