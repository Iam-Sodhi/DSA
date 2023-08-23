#include <bits/stdc++.h>
using namespace std;
//This is the second part of last q where we will solve the q using DP with binary search in O(nlogn) time complexity
//****Remember****
//std::lower_bound - returns iterator to first element in the given range which is EQUAL_TO or Greater than val.
// std::upper_bound - returns iterator to first element in the given range which is Greater than val. ***can't be used here reason below ->overflow*****
int solveOptimal(vector<int>& nums){
    if(nums.size()==0){
        return 0;
    }
    int n=nums.size();
    vector<int> ans; //*****This ans will not be the req subsequence just its length will be the same as longest inc subsequence
    ans.push_back(nums[0]); // first element we do not need to compare with anyone 
    for (int  i = 1; i < n; i++)
    {
        if(nums[i]>ans.back()){ //push it in the ans
            ans.push_back(nums[i]);
        }
        else{
            //find the index of the just bada element(or equal ele) in ans using binary search
            int idx=lower_bound(ans.begin(), ans.end(),nums[i])- ans.begin(); //upper_bound can't be used here as if no larger element found then return a.end() means ans[n] if lenght=n -> overflow
            //but lower bound will atleast return the idx of equal element which will be present there as this is the conditon of else (<=)
            ans[idx]=nums[i];
        }
    }
    return ans.size();
}
int main()
{	 vector<int> a;
    a.push_back(1);
    a.push_back(5);
    cout<<*(a.end())<<endl;
    cout<<*(a.end()-1);
    return 0;
}