#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
//Given an m x n binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.
//  // top-down approach
  int solveMem(vector<vector<char>>& matrix,int i,int j,int &maxi,vector<vector<int>>& dp){
     if(i>=matrix.size() ||j>=matrix[0].size() ){
         return 0;
     }
     if(dp[i][j]!=-1){  //dp[i][j] store the max square which can be in right,left& diagnol(right-down) of i& j index including that index also
         return dp[i][j];
     }
     int right=solveMem(matrix,i,j+1,maxi,dp);
     int diagonal=solveMem(matrix,i+1,j+1,maxi,dp);
     int bottom=solveMem(matrix,i+1,j,maxi,dp);
     if(matrix[i][j]=='1'){
        dp[i][j]=1+min(right,min(diagonal,bottom));
        maxi=max(dp[i][j],maxi);
       return dp[i][j] ;
     }
     else 
     return dp[i][j]=0;
  }
  //bottom up approach
  int solveTab(vector<vector<char>>& matrix,int& maxi){
       vector<vector<int>> dp(matrix.size()+1,vector<int>(matrix[0].size()+1,0));
       int n=matrix.size();
       int m=matrix[0].size();
       for(int i=n-1;i>=0;i--){  // loop is started from n-1 as bottom up approach
           for(int j= m-1;j>=0;j--){
              int right=dp[i][j+1];
       int diagonal=dp[i+1][j+1];
     int bottom=dp[i+1][j];
       if(matrix[i][j]=='1'){
        dp[i][j]=1+min(right,min(diagonal,bottom));
        maxi=max(dp[i][j],maxi); 
     }
     else dp[i][j]=0;
           }
       }    
      return dp[0][0];
  }

// Possible as dp[i][j] depends on curr and next row
 int solveSpace(vector<vector<char>>& matrix,int& maxi){
       int n=matrix.size();
       int m=matrix[0].size();
       vector<int> curr(m+1,0); //
       vector<int>next(m+1,0);
       for(int i=n-1;i>=0;i--){  // loop is started from n-1 as bottom up approach
           for(int j= m-1;j>=0;j--){
              int right=curr[j+1];
       int diagonal=next[j+1];
     int bottom=next[j];
       if(matrix[i][j]=='1'){
        curr[j]=1+min(right,min(diagonal,bottom));
        maxi=max(curr[j],maxi); 
     }
     else curr[j]=0;
           }
           next=curr;
       }    
      return next[0];
  }

int main()
{	
     int maxi=0;
      // vector<vector<char>>matrix={{"1","0","1","0","0"},{"1","0","1","1","1"},{"1","1","1","1","1"},{"1","0","0","1","0"}};
        // vector<vector<int>> dp(matrix.size(),vector<int>(matrix[0].size(),-1));
        // solveMem(matrix,0,0,maxi,dp);
        //solveTab(matrix,maxi);
       //solveSpace(matrix,maxi);
        return maxi*maxi;
    return 0;
}