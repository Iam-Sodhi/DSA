#include <iostream>
using namespace std;
//*****Record braking day*****
int main()
{	int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    if (n==1)
    {
        cout<<"1"<<endl;
        return 0;
    }
    
   int mx= -1;
   int res=0;
   for (int j =0 ; j < n-1; j++)
   {
     
     if (a[j]>mx &&a[j]>a[j+1] )
     {  res++;
        
     }
     mx=max(a[j],mx);
     
     
   }
   if (a[n-1]>mx)
   {
    res++;
   }
   
   cout<<"The number of record breaking days are "<<res<<endl;
    return 0;
}