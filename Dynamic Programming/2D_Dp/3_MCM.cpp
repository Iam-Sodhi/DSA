#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

// Given the dimension of a sequence of matrices in an array arr[], where the dimension of the ith matrix is (arr[i-1] * arr[i]), 
//  arr[] = {40, 20, 30, 10, 30}
// Output: 26000
// Explanation:There are 4 matrices of dimensions 40×20, 20×30, 30×10, 10×30.
// Let the input 4 matrices be A, B, C and D.
// the task is to find the most efficient way to multiply these matrices together such that the total number of element multiplications is minimum.
// Two matrices of size m*n and n*p when multiplied, they generate a matrix of size m*p and the number of multiplications performed are m*n*p.
// Now, for a given chain of N matrices, the first partition can be done in N-1 ways. 
// For example, sequence of matrices A, B, C and D can be grouped as (A)(BCD), (AB)(CD) or (ABC)(D) in these 3 ways. 
int matrixChainMemoised(int* p, int i, int j,vector<vector<int> >& dp)
{   //here 1 is passed as i as p[i-1]& p[i] is dimension of first matrix
    if (i == j)
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    int ans = INT_MAX;
    for (int k = i; k < j; k++)
    {  //observe carefully here we are like giving brackets to divide into two groups and also storing the result which we will get after the groups(unke elements multiply hoke bas ek ek hi bachega) will multiply with each other
       // (AB) & (CD) here from first group*after being multiplied) we will always have dimension that can be multiplied with other group. YOu can observe.
        ans= min(ans, matrixChainMemoised(p, i, k,dp)+ matrixChainMemoised(p, k + 1, j,dp) + p[i - 1] * p[k] * p[j]); //hence storing the multiplication value along with formation of groups
    }
    return dp[i][j]=ans;
}
// Driver Code
int main()
{
    int arr[] = { 1, 2, 3, 4 }; //means 3 matrices
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<vector<int>>dp(1000,vector<int>(1000,-1));
    cout << "Minimum number of multiplications is " << matrixChainMemoised(arr, 1, n-1,dp);//here 1 is passed as i
}
 