#include <iostream>
using namespace std;
//Find if a given element is present in sorted & Rotated array in log(n)  complexibilty
int pivotPoint(int a[], int n)
{
    int st = 0;
    int end = n-1;
  
    while (st <end)
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
int binarysearch(int a[], int s, int e,int key){
    int mid;
    while (s<=e)
    {
        mid=(s+e)/2;
        if (key<a[mid])
        {
            e=mid-1;
        }
        else if (key>a[mid])
        {
            s=mid+1;
        }
        else
        {
            return mid;
        }
        
    }
    return -1;
}
int main()
{   int a[]={7,9,1,2,3};
    int n= sizeof(a)/sizeof(a[0]);
    int pivot=pivotPoint(a,n);
    int key;
    cin>>key;
    int ans;
    if (a[pivot]<=key && key<=a[n-1])
    {
         ans= binarysearch(a,pivot,n-1,key);
    }
    else
    {
        ans=binarysearch(a,0, pivot-1,key);
    }
    cout<<"The target is present at "<<ans<<" index"<<endl;
    return 0;
}