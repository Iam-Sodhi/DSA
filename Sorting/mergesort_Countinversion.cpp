#include <iostream>
using namespace std;
// Find the number of inversions in the array not using brute force approach
long long  merge(int a[], int low, int high, int mid)
{
    int i, j, k;
    i = low;
    j = mid + 1;
    k = low;
    int b[high];
    long long inv=0;
    while (i <= mid && j <= high) // Remember to use = sign as they are index
    {
        if (a[i] < a[j])
        {
            b[k] = a[i];
            i++;
            k++;
        }
        else
        {
            b[k] = a[j];    
            inv+=(mid-low+1)-i; // as if a[i]>a[j] for i<j , then a[i+1],a[i+2],--- are also >a[j] as the subarray is sorted
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        b[k] = a[i];
        i++;
        k++;
    }
    while (j <= high)
    {
        b[k] = a[j];
        j++;
        k++;
    }
    for (int i = 0; i < high + 1; i++) 
    {
        a[i] = b[i];
    }
    return inv;
}
long long  Merge_sort(int a[], int low, int high) 
{
    long long inv =0;
  
    if (low < high)
    {
        int mid = (low + high) / 2;
       inv+= Merge_sort(a, low, mid); 
       inv+= Merge_sort(a, mid + 1, high);
      inv+=  merge(a, low, high, mid);
    }
    return inv;
}
int main()
{	int n;
    
   cin>>n;
   int a[n];
   for (int i = 0; i < n; i++)
   {
    cin>>a[i];
   }
   cout<<Merge_sort(a,0,n-1);
   
    return 0;
}