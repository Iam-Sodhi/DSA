#include <bits/stdc++.h>
using namespace std;
// The next greater element of some element x in an array is the first greater element that is to the right of x in the same array.
// You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a subset of nums2.
// For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] and determine the next greater element of nums2[j] in nums2.
// If there is no next greater element, then the answer for this query is -1.
// Return an array ans of length nums1.length such that ans[i] is the next greater element as described above.


//for prev greater element , start loop form 0 index
//****prev smaller or next smaller element type questions can also be solve using this
vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
{
    unordered_map<int, int> mp;
    stack<int> s;
    s.push(1e5);
    for (int i = nums2.size() - 1; i >= 0; i--)
    {
        while (s.top() <= nums2[i])
        {
            s.pop();
        }
        if (s.top() == 1e5)
            mp[nums2[i]] = -1;
        else
            mp[nums2[i]] = s.top();
        s.push(nums2[i]);
    }
    vector<int> ans(nums1.size());
    for (int i = 0; i < nums1.size(); i++)
    {
        ans[i] = mp[nums1[i]];
    }
    return ans;
}
int main()
{
    return 0;
}