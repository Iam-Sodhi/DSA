#include <iostream>
#include<map>
#include<unordered_map>
#include<vector>
//unordered_map has time complexibilty of O(1) in terms of insersion, deletion etc
//OrderedMap has time complexibilty of O(logn)
//But Unordered Map does not store the data in order we input it 
//The default behavior of map(ordered) is to store elements in ascending order.
//To store in descending order , Use:     // map<key_datatype, value_datatype, greater<int> > mapName;
using namespace std;
int main()
{	 unordered_map<int, vector<int>> mp;
    mp[0]={1,2,4};
    mp[1]={5,6,7};
     for(auto i: mp) {
        cout<<i.first<<": ";
        for (int j = 0; j < i.second.size(); j++)
        {
            cout<<i.second[j]<<" ";
        }
        cout<<endl;
     }
    

    return 0;
}