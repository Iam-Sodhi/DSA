#include <iostream>
#include <map>
#include <vector>
#include <unordered_map>
#include<algorithm>
using namespace std;
// Find the top most frequent elements in the stream
// e.g. given an array : 1 2 2 2 3 4 and k=2
// We have to output elements in decreasing frequency till we reach (K+1)th distinct elements.
// here our output is  2 -> 3 & 1-> 1
int main()
{ // We will use map as we need our output in decreasing frequency
    // by default it is in increasing order
    // But we can't even use: map<key_datatype, value_datatype, greater<int> > mapName;
    // as above mentioned will give descending order wrt key datatype not value datatype
    // but we need our answer wrt to frquencey (that is going to be our value in the mapping)

    unordered_map<int, int> mp;
    vector<int> a={2,1,1,1,3,4};
    int k=2;
    for (int i = 0; i < a.size(); i++)
    {
        if (mp.size()==k && mp[a[i]]==0) //*****here mp[3] will also get initialized*****
        {                             // hence we need to check it while showing our output
           break; //AS we need only k first distint elements
        }
        mp[a[i]]++;
    }
    //Now to sort in descending order, use a vector 
    vector<pair<int, int>> v;
    for (auto x : mp)
    {
        v.push_back(make_pair(x.second, x.first)); // push the frequency first
    }
    sort(v.begin(), v.end(), greater<pair<int, int>>());

    for(auto i: v){
        if (i.first!=0)  // to check the k+1 the element which got initialize to 0 
        {
             cout<<i.second<<" "<<i.first<<endl;
        }
        
       
    }
    
    return 0;
}