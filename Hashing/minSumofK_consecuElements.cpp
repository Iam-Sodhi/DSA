#include <iostream>
#include <vector>
using namespace std;
//Sliding Window Technique
//Your are given an array with n elements, calculate the minimum sum of k consecutive elements 

int main()
{	 vector<int> a={-2,10,1,3,2,-2,4,5};
     int k=3;
      // firstly find the sum of first k elements
      int sum=0;
      
      for (int i = 0; i < k; i++)
      {
        sum+=a[i];
      }
     int ans=sum;
     for (int i = k; i < a.size(); i++)
     {   sum= sum - a[i-k] + a[i];
        ans=min(ans,sum);
        
     }
     cout<<"The minimum sum of k consecutive elements: "<<ans<<endl;
      
    return 0;
}