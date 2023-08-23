#include <iostream>
#include<map>
#include<vector>
#include<unordered_map>
using namespace std;
//Find the maximum occuring element in the array. If two elements or more have same max frequency then ans 
//should be the one which comes first (means have lower index).

int main()
{	 unordered_map<int,int> count;  // we ayr using unordered_map as it has better time complexbilty but we need to keep in mind it doesn't store input in ordered way.
     vector<int> a= {1,2,5,3,9,1,3,2,3,2}; //here 3 and 2 have same max frequency
     int maxfrequency =INT8_MIN;
     for (int i = 0; i < a.size(); i++)
     {
        count[a[i]]++;
        maxfrequency=max(maxfrequency,count[a[i]]);
     }
     //now we will traverse the array not the map so that we can traverse it from 0 to higher index orderly
     // our unordered_map may not store 0 index at first as it is undordered
     int ans;
     for (int i = 0; i < a.size(); i++)
     {
        if(count[a[i]]==maxfrequency)
        {
             ans=a[i];
             break;  // so that the lower index wala store ho je exit ho jaye hmara loop
        }
     }
     
    cout<<"The Element with maximum occuring frequency is "<<ans<<endl;

    return 0;
}