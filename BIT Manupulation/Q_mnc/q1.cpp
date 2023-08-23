#include <iostream>
using namespace std;
// find the unique number from the array  where all elements are present twice except one element
int unique(int a[], int n)
{  int xorsum=0;
   for (int i = 0; i < n; i++)
   {
    xorsum=xorsum^a[i];  // as 4*4=0 & only the unique element will be remaining
   }
   return xorsum;
}
int main()
{   int a[]={1,2,3,4,1,5,5,2,3};
    int n=sizeof(a)/sizeof(a[0]);
     cout<<unique(a,n);
    return 0;
}