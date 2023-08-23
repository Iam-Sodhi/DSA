#include <iostream>
using namespace std;
// Find Pivot point  in O(logn) complexibility
int pivotPoint(int a[], int n)
{
    int st = 0;
    int end = n-1;
  
    while (st <end) // don't do st<=end as end=mid hence it may repeating again and again when st=en and en= mid
    {  int mid= (st+end)/2;
        if (a[mid] >= a[0])
        { st=mid+1;
        }
        else
        {
            end=mid;  // *****here don't do mid-1 ( as it pivot is less than a[0] so it could be at mid , hence if do mid-1 then it will be ignored)
        }
        
    }
    return st;  //*****return st here***** we can see by dry run
    //here index is returned
}
int main()
{   int a[]={7,9,1,2,3};
    int n= sizeof(a)/sizeof(a[0]);
    cout<<"The index of pivot point : "<<pivotPoint(a,n); 
    return 0;
}