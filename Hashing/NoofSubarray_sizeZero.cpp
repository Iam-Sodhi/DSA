#include <iostream>
#include <map>
#include <vector>
#include <unordered_map>
using namespace std;
// we can either use the brute force approach
//or use the hashign mehtod algorithm
int main()
{	vector<int> a={1,-1,1,-1};
    
     // firstly we will compute the prefix sum w.r.t first element
     int pref_sum=0;
     unordered_map<int,int> cnt;
     for (int i = 0; i <a.size(); i++)
     {
        pref_sum+= a[i];   // it will be 1 0 1 0
         cnt[pref_sum]++;
     }
     int ans=0;
     for(auto i: cnt){
        int c=i.second;  
        // we will use permutation & combination 
        //e.g if sum is 1 and its count is 3, then total subarrys with 0 sum will be 3C2.
        ans+=(c*(c-1))/2; // e.g 1 0 1 0 then for 1, no of subarrays with sum 0 are = 2C2
        //
        //****THis is also a case which we need to add to the ans when 
        if (i.first==0)
        {
            ans+=i.second;
        }
        
     }
     cout<<"The no of subarrays with sum zero are "<<ans<<endl;
    return 0;
}