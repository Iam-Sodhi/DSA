#include <bits/stdc++.h>
using namespace std;
//******IMP Problem***** Classical & Interview mai puche jane wala question
// You are given two integer arrays of the same length nums1 and nums2. In one operation, you are allowed to swap nums1[i] with nums2[i].
// For example, if nums1 = [1,2,3,8], and nums2 = [5,6,7,4], you can swap the element at i = 3 to obtain nums1 = [1,2,3,4] and nums2 = [5,6,7,8].
// Return the minimum number of needed operations to make nums1 and nums2 strictly increasing.
// The test cases are generated so that the given input always makes it possible.
// An array arr is strictly increasing if and only if arr[0] < arr[1] < arr[2] < ... < arr[arr.length - 1].

//***** Require carefull attention to observe different condition
// ***** if curr element is already strictly greater than the corresponding prev elements of resp arrays, then may not  swap at that index but otherwise we have to swap no matter what
// but if its not so, then we need to confirm that after swapping the the new elements will greater than the previous elements, then there we can do swap otherwise we can't
// it is given in question that both arrays can be made inc always so no need to worry about that
// we will use a swapped variable to know whether the prev elements of resp arrays were swapped or not ( will help in checking checking condition)
int solveMem(vector<int> &nums1, vector<int> &nums2, int idx, int swapped, vector<vector<int>> &dp)
{
    if (idx == nums1.size())
        return 0;
    if (dp[idx][swapped] != -1)
        return dp[idx][swapped];

    int prev1 = (idx == 0) ? -1 : nums1[idx - 1];
    int prev2 = (idx == 0) ? -1 : nums2[idx - 1];
    if (swapped)
    {
        swap(prev1, prev2); // we do not want to actually change the values at there places (& swap() works on call by reference)
        // hence we are making use of two differnt variable prev1 and prev2 & in case swapped==1 then there values will be interchanged
        // so that our condition that prev elements were swapped become true (not actually like at their position in their arrays)
        // dry run to understand better -> now our next conditions will be according these values as theri prev elements
    }
    int ans = INT_MAX;
    
    if (nums1[idx] > prev1 && nums2[idx] > prev2)
    {                                                 // here we have our choice even to left swapping
        ans = solveMem(nums1, nums2, idx + 1, 0, dp); // swapped =0 as not swapping here
    }
    // now we  swap if (after swapping our arrays are becoming inc till that part)
    if (nums1[idx] > prev2 && nums2[idx] > prev1) // see here it is being checked that after swapping whether the req condition will be satisfied or not
    {
        ans = min(ans, 1 + solveMem(nums1, nums2, idx + 1, 1, dp));
    }
    // out of two above condition , ans must come from one of them as already given in Q that test cases are made so
    return dp[idx][swapped] = ans;
}
int solveTab(vector<int> &nums1, vector<int> &nums2)
{
    vector<vector<int>> dp(nums1.size() + 1, vector<int>(2, 0));

    for (int idx = nums1.size() - 1; idx >= 0; idx--)
    {
        for (int swapped = 1; swapped >= 0; swapped--)
        {
            int prev1 = (idx == 0) ? -1 : nums1[idx - 1];
            int prev2 = (idx == 0) ? -1 : nums2[idx - 1];
            if (swapped)
            {
                swap(prev1, prev2);
            }
            int ans = INT_MAX;
            if (nums1[idx] > prev1 && nums2[idx] > prev2)
            {
                ans = dp[idx + 1][0]; // swapped =0 as not swapping here
            }
            if (nums1[idx] > prev2 && nums2[idx] > prev1)
            {
                ans = min(ans, 1 + dp[idx + 1][1]);
            }
            dp[idx][swapped] = ans;
        }
    }
    return dp[0][0];
}
int solveSpace(vector<int> &nums1, vector<int> &nums2)
{
    vector<vector<int>> dp(nums1.size() + 1, vector<int>(2, 0));
    vector<int> curr(2,0);
    vector<int> next(2,0);

    for (int idx = nums1.size() - 1; idx >= 0; idx--)
    {
        for (int swapped = 1; swapped >= 0; swapped--)
        {
            int prev1 = (idx == 0) ? -1 : nums1[idx - 1];
            int prev2 = (idx == 0) ? -1 : nums2[idx - 1];
            if (swapped)
            {
                swap(prev1, prev2);
            }
            int ans = INT_MAX;
            if (nums1[idx] > prev1 && nums2[idx] > prev2)
            {
                ans = next[0]; // swapped =0 as not swapping here
            }
            if (nums1[idx] > prev2 && nums2[idx] > prev1)
            {
                ans = min(ans, 1 + next[1]);
            }
            curr[swapped] = ans;
        }
        next=curr;
    }
    return next[0];
}

int minSwap(vector<int> &nums1, vector<int> &nums2)
{
    vector<vector<int>> dp(nums1.size() + 1, vector<int>(2, -1));
    return solveMem(nums1, nums2, 0, 0, dp); // initially swapped =0
}
int main()
{
    return 0;
}