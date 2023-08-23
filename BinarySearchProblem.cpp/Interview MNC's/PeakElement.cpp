#include <iostream>
#include<vector>
using namespace std;
//*****Peak Element in a Mountain*****
// arr.length >=3
// Find peak index of the Mountain element
 int peakElement(int a[], int n){
    int s=0;
    int e=n-1;
    while (s<e) // here don't do s<=e as end=mid here not mid -1 hence it may start repeating itself when s=e and condition is for e=mid;
    {
        int mid= s+ (e-s)/2;
        if (a[mid]<a[mid+1])
        {
           
            s=mid+1;

        }
        else // either a[mid-1]<a[mid]>a[mid+1]  or just a[mid]> a[mid+1]
        {
            e= mid; //here end=mid as this could also contain when mid is the peak
        }
        
    }
    return s;
 }
 //OR
      int isTrue(vector<int>& arr, int i){
         if(i!=0 && i!=arr.size()-1){
             if(arr[i]>arr[i-1] && arr[i]>arr[i+1]) return 1;
         }
         return 0;
     }


    int peakIndexInMountainArray(vector<int>& arr) {
        int start=1;
        int end=arr.size()-1;


        while(start<end){
                int mid= start +(end-start)/2;
                if(isTrue(arr,mid)) return mid;
                else if( arr[mid]<arr[mid-1]){
                    end=mid;
                }
                else{
                    start= mid;
                }
        }
        return -1;
    }
int main()
{
    int a[] = {3, 4, 5, 10,8,5,1};
    int n = sizeof(a) / sizeof(a[0]);
    cout<<"The peak element is at index "<<peakElement(a,n);
    return 0;
}