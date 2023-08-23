#include <iostream>
#include<climits>
using namespace std;
// To find max sum of the sub arrays
//We have many methods to solve this 1. O(n^3) if we use q1 like approach 2. O(n^2) if we use cumulative sum approach
//*****We will use KADANE'S Algorithm to solve this O(n)->better approach
int main()
{	
   int n;
   cin>>n;
   int a[n];
   for (int i = 0; i < n; i++)
   {
    cin>>a[i];
   }
   
   int currsum=0;
   int maxsum=INT_MIN;
   for (int i = 0; i < n; i++)
   {
       currsum+=a[i];
       if (currsum<0)
       {
        currsum=0;
       }
       maxsum=max(maxsum,currsum);
   }
   cout<<"The max sum of the subarrays is "<<maxsum<<endl;
    return 0;
}