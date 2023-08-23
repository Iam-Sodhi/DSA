#include <iostream>
#include<climits>
using namespace std;
// To find maximum circular subarray sum
int Kadane(int a[],int n){
      
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
   return maxsum;
}
int main()
{	 int n;
   cin>>n;
   int a[n];
   for (int i = 0; i < n; i++)
   {
    cin>>a[i];
   }

    int nonwrapsum, wrapsum;// as two cases are formed other when no need to wrap
     nonwrapsum=Kadane(a,n);

     //wrapsum=sum of all elements - sum of non-contributing elements
     // to find non-contributing elements first we need to change the sign of elements then find max sum whose negative will be our req sum
     int total_sum=0;
     for (int i = 0; i < n; i++)
     {
        total_sum+=a[i];
        a[i]=-a[i];
     }
     wrapsum=total_sum + Kadane(a,n); //total sum - (-Kadane)
     
     //now we need to check which give max sum
     int maxsum= INT_MIN;
      maxsum=max(nonwrapsum,wrapsum);
    cout<<"The max sum is "<<maxsum;    
    return 0;
}