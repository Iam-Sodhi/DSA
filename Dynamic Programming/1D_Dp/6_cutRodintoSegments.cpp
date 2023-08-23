#include <iostream>
#include <vector>
#include<climits>
#include <algorithm>
using namespace std;
//N is the length of the rod. You ned to determine the max number of segments you can make of this rod provided that each segment should be of length x , y, and z.

//M1
int cutSegmentsMem(int n, int x,int y,int z,vector<int>&dp){
    if (n==0)
    {
        return 0;
    }
    if (n<0)
    {
        return  INT_MIN;
    }
   if (dp[n]!=-1)
   {
    return dp[n];
   }
   
    int a= 1+ cutSegmentsMem(n-x,x,y,z,dp);
    int b= 1+ cutSegmentsMem(n-y,x,y,z,dp);
    int c= 1+ cutSegmentsMem(n-z,x,y,z,dp);

    int ans=max(a,max(b,c));
    return dp[n]=ans;
}

//M2
int cutSegmentsTab(int n,int x,int y,int z){
    vector<int> dp(n+1,INT_MIN);
    //dp[i] store the max no of segments taken to form i length of rod
    dp[0]=0;

    for (int i = 1; i <=n; i++)
    {  if(i-x>=0)
       dp[i]=max(dp[i],1+dp[i-x]);
       if(i-y>=0)
        dp[i]=max(dp[i],1+dp[i-y]);
       if(i-z>=0)
       dp[i]=max(dp[i],1+dp[i-z]);
    
    }
    if (dp[n]<0) //n can't be made using given segments
    {
        return -1;
    }
    return dp[n];
    
}

//here dp[i] depends on dp[i-x],dp[i-y] & dp[i-z]  but we can't track the values of x ,y and z  
//hence we can't use the space optimization like the previous methods
int main()
{	 int n=9;      
     int x=5,y=3,z=2;  //here max will be when we will use 3 '2' wali and 1 '3' wali ->total=4

     vector<int>dp(n+1,-1);
     cout<<cutSegmentsMem(n,x,y,z,dp)<<endl;
     cout<<cutSegmentsTab(n,x,y,z)<<endl;
    return 0;
}