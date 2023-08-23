#include <bits/stdc++.h>
using namespace std;
//****IMP****
//Use binary search with DP  approach very similar to last Q  
//just we need to first sort it in the way that widht in ascending order and for items with same width sort acc to their height that larger height comes first (descending wrt height)
//then apply last Q approach on the height wala arrayYou are given a 2D array of integers envelopes where envelopes[i] = [wi, hi] represents the width and the height of an envelope.

// One envelope can fit into another if and only if both the width and height of one envelope are greater than
// the other envelope's width and height.
// Return the maximum number of envelopes you can Russian doll (i.e., put one inside the other).
// Note: You cannot rotate an envelope.
//  envelopes = [[5,4],[6,4],[6,7],[2,3]]
// Output: 3
// Explanation: The maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).
static bool cmp(vector<int>& a, vector<int>& b){ //let widht be at 0 idx and height at 1 idx
  if(a[0]!=b[0]) return a[0]< b[0];
  else return a[1]>b[1];
}
  int maxEnvelopes(vector<vector<int>>& a) {
            int n=a.size();
            if(n==0) return 0;
    //let's sort acc to the approach discussed above
    sort(a.begin(),a.end(),cmp);
    //new use same approach used in finding the longest inc subsequence wrt the height elements

    vector<int> ans;
     ans.push_back(a[0][1]);
    for(int i=1;i<n;i++){
        if(a[i][1]>ans.back()) ans.push_back(a[i][1]);
        else{
            // just find the bada wala element than a[i] using lower bound (not upper bound as may return ans.end() in case no larger element found)
            int idx=lower_bound(ans.begin(),ans.end(),a[i][1])-ans.begin();
            ans[idx]=a[i][1];
        }
    }
    return  ans.size();
    }
int main()
{	
    return 0;
}