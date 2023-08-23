#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// A thief can carry a max weight of W into his knapsack. There are n items and the ith items wiehts wi adn is of value vi.
// You have to find the max value that a thief can generate by stealing items.

// we will see there are 2 ching variables or states in recursive function, therefore 2D DP
// M1
int maxValueMem(vector<int> &weight, vector<int> &value, int i, int W, vector<vector<int>> &dp)
{               // here i is the last index
    if (i == 0) // when only one item is left then if possible there is no harm to add it
    {
        if (weight[0] <= W)
        {
            return value[0];
        }
        else
            return 0;
    }
    // dp[i][capacity] stores the max value carried upto ith index items if the max capacity is 'capacity'
    if (dp[i][W] != -1)
    {
        return dp[i][W];
    }
    int incl = 0;
    if (weight[i] <= W)
    {
        incl = value[i] + maxValueMem(weight, value, i - 1, W - weight[i], dp);
    }
    int excl = 0 + maxValueMem(weight, value, i - 1, W, dp);
    int ans = max(incl, excl);
    return dp[i][W] = ans;
}

// M2
int maxValueTab(vector<int> &weight, vector<int> &value, int n, int W)  //SC= O(n*W)
{ // here n is the no of items not the last index
    vector<vector<int>> dp(n, vector<int>(W + 1, 0));
    // Base condition
    for (int i = 0; i <= W; i++)
    {
        if (weight[0] <= i)
            dp[0][i] = value[0];
        // else dp[0][i]=0 ; //as already equal
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            int incl = 0;
            if (weight[i] <= j)
            {
                incl = value[i] + dp[i - 1][j - weight[i]];
            }
            int excl = 0 + dp[i - 1][j];
            dp[i][j] = max(incl, excl);
        }
    }
    return dp[n - 1][W];
}

// M3
int maxValueSpace(vector<int> &weight, vector<int> &value, int n, int W)  // Space Complexity O(2*W)
{  // here n is the no of items not the last index
    vector<int> prev(W+1,0);  // it is for i=0 and all the weight till 
    vector<int> curr(W+1,0);
    for (int i = 0; i <= W; i++)
    {
        if (weight[0] <= i)
            prev[i] = value[0];
        // else dp[0][i]=0 ; //as already equal
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            int incl = 0;
            if (weight[i] <= j)
            {
                incl = value[i] + prev[j-weight[i]];
            }
            int excl = 0 + prev[j];
             curr[j] = max(incl, excl);
        }
        prev=curr;
    }
    return curr[W];
}

//Stiil we can improve  as curr[i] depends on (prev[0] to prev[i]) & the prev[i]
//But *****Works only when Right to left Traversal of i****
int maxValueSpace2(vector<int> &weight, vector<int> &value, int n, int W) //Better space complexibilty O(W)
{  
    vector<int> curr(W+1,0);
    for (int i = 0; i <= W; i++)
    {
        if (weight[0] <= i)
            curr[i] = value[0];
        // else dp[0][i]=0 ; //as already equal
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = W; j >= 0; j--)
        {
            int incl = 0;
            if (weight[i] <= j)
            {
                incl = value[i] + curr[j-weight[i]];
            }
            int excl = 0 + curr[j];
             curr[j] = max(incl, excl);
        }
    }
    return curr[W];
}
int main()
{
    vector<int> weight = {1, 2, 4, 5};
    vector<int> value = {5, 4, 8, 6};
    int n = 4;
    int W = 5;

    vector<vector<int>> dp(n, vector<int>(W + 1, -1));        // as max n-1 index needed and W capacity needed
    cout << maxValueMem(weight, value, n - 1, W, dp) << endl; // Remember to pass the last index here not the size

    cout << maxValueTab(weight, value, n, W) << endl;
    cout << maxValueSpace(weight, value, n, W) << endl;
    cout << maxValueSpace2(weight, value, n, W) << endl;
    return 0;
}