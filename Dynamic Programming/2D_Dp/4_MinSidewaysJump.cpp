#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
//******IMP problem****** carefully observe the Tabulation approach & also it space optimization is based on columns 

// There is a 3 lane road of length n that consists of n + 1 points labeled from 0 to n. A frog starts at point 0 in the second lane and wants to jump to point n. However, there could be obstacles along the way.
// You are given an array obstacles of length n + 1 where each obstacles[i] (ranging from 0 to 3) describes an obstacle on the lane obstacles[i] at point i.
// If obstacles[i] == 0, there are no obstacles at point i. There will be at most one obstacle in the 3 lanes at each point.
// For example, if obstacles[2] == 1, then there is an obstacle on lane 1 at point 2.
// The frog can only travel from point i to point i + 1 on the same lane if there is not an obstacle on the lane at point i + 1.
// To avoid obstacles, the frog can also perform a side jump to jump to another lane (even if they are not adjacent) at the same point if there is no obstacle on the new lane.
// For example, the frog can jump from lane 3 at point 3 to lane 1 at point 3.
// Return the minimum number of side jumps the frog needs to reach any lane at point n starting from lane 2 at point 0.
// Note: There will be no obstacles on points 0 and n.
int solveMem(vector<int> &obstacles, int currPos, int currLane, vector<vector<int>> &dp)
{
    int n = obstacles.size();
    if (currPos == n - 1)
    {
        return 0;
    }
    if (dp[currPos][currLane] != -1)
    {
        return dp[currPos][currLane];
    }

    // if no obstacle present in pos+1 of same lane then no need to jump
    if (obstacles[currPos + 1] != currLane)
    {
        return dp[currPos][currLane] = solveMem(obstacles, currPos + 1, currLane, dp);
    }
    else
    {
        int ans = INT_MAX;
        // we can jump to other two lanes provided there should be no obstacle
        for (int i = 1; i <= 3; i++)
        {
            if (i != currLane && obstacles[currPos] != i)
            { // i!=currLane as we don't want to jump at the same pt , it's pointless
                ans = min(ans, 1 + solveMem(obstacles, currPos, i, dp));
            }
        }
        return dp[currPos][currLane] = ans;
    }
}
//*****see carefully there is one trick here*****
int solveTab(vector<int> &obstacles)
{
    int n = obstacles.size();
    vector<vector<int>> dp(n, vector<int>(4,1e9));
    // Base condition
    for (int i = 0; i <= 3; i++)
        dp[n - 1][i] = 0;

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = 1; j <= 3; j++)
        {

            if (obstacles[i + 1] != j)
            {
                dp[i][j] = dp[i + 1][j];
            }
            else
            {
                  int ans=1e9;
                // we can jump to other two lanes provided there should be no obstacle
                for (int k = 1; k <= 3; k++)
                {
                    if (k != j && obstacles[i] != k)
                    { // i!=currLane as we don't want to jump at the same pt , it's pointless
                ans = min(ans, 1 + dp[i+1][k]); ///*****i+1 means currPos+1 here observe otherwise  1e9 wali value dp[i][j] ko milegi as kyuki hmara j->1 to 3 range kr raha hai isliye dp[i][j] ko dp[i][k(equalj+1)] ke value mil jayegi jo ke 1e9 hogi
                // kyuki abhi tak hum wahan tak pahunche hi nhi hai , hence we increase the pos so that we get dp[i+1][k] wali ke equal kr denge as after k==j+1(waha pahunch jayega use bhi wohi value milegi)
                    }
                }
                dp[i][j]=ans;

            }
        }
    }
    return min(dp[0][2],min(1+dp[0][1],1+dp[0][3])); // as need to be at 0,2 index but we can also go there from other two lanes and update the ans if we get less jumps+1
}
//space optimization possible as dp[currpos][currlane] depends on dp[nextpos][currlane] or dp[nextpost][1-3] 
//but here it is depending on nextpos wali row  only means next column of the lane if we use vector<vector<int>> dp(4, vector<int>(n,1e9)); lanes as rows and pos as columns 
int solveSpace(vector<int>& obstacles){
    int n=obstacles.size();
    //we can also do it like this like the question given here to get better reality
    // vector<vector<int>> dp(4, vector<int>(n,1e9));
    vector<int> curr(4,1e9);
    vector<int> next(4,1e9);
    for(int i=0;i<=3;i++)
    next[i]=0;

     for (int i = n - 2; i >= 0; i--)
    {
        for (int j = 1; j <= 3; j++)
        {

            if (obstacles[i + 1] != j)
            {
                curr[j] = next[j];
            }
             else
            {    int ans=1e9;
                for (int k = 1; k <= 3; k++)
                {
                    if (k != j && obstacles[i] != k)
                    { 
                ans= min(ans, 1 +next[k]); 
                    }
                }
                curr[j]=ans;
            }

           
        }
         next=curr;
    }
    return min(next[2],min(1+next[1],1+next[3]));
}
int main()
{ // obstacles = [0,1,2,3,0]

    //    int n=obstacles.size();
    //          vector<vector<int> > dp(n,vector<int>(4,-1));
    // return solveMem(obstacles,0,2,dp);  //we pass 2 lane intially as given in Q
    return 0;
}