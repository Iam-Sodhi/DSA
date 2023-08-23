#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//*****DP is applied when there are overlapping subproblems*****
// DP -> 3 ways
// 1.top to bottom + Recursion, with memorisation
// 2.bottom to top, tabulation
// 3. Space optimization

// here we will use it to print the nth term of fibonacci series
//*****Method 1***** -> top to bottom
int fibbo(int n, vector<int> dp)
{ // T.C.= O(n) , S.C.=O(n)+O(n)
    if (n == 0 || n == 1)
    {
        return n;
    }
    // now check if that n is already in dp array
    if (dp[n] != -1)
    {
        return dp[n];
    }

    return dp[n] = fibbo(n - 1, dp) + fibbo(n - 2, dp);
}

//*****METHOD 2*****-> bottom to top, tabulation
int fibbo2(int n){ // T.C.= O(n) , S.C.= O(n) hence more efficient
   //first make dp array
  vector<int> dp(n+1);
  //write base conditions 
  dp[0]=0;
  dp[1]=1;
  for (int i = 2; i <=n; i++)
  {
     dp[i]=dp[i-1]+dp[i-2];
  }
  
   return dp[n];

}

//*****Method3*****-> space optimization ( requre brain storming)
 int fibbo3(int n){ // T.C.= O(n) , S.C.=O(1)
    if(n==0)
    return 0;
    int dp1=0;
    int dp2=1;
    for (int i = 2; i <=n; i++)
    {   int t=dp1+dp2;
         dp1=dp2;
         dp2=t;
        
    }
    return dp2;
    
 }
int main()
{
    int n = 5;
    vector<int> dp(n + 1); // size if n+1 as indexing start from 0
    // initialize all the elements of dp to -1 initially
    for (int i = 0; i <=n; i++)
    {
        dp[i] = -1;
    }
    
    cout << fibbo(n, dp)<<endl;
    cout<<fibbo2(n)<<endl;
    cout<<fibbo3(n)<<endl;
    return 0;
}