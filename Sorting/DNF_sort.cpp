#include <iostream>
using namespace std;
// O(n) complexibitlity
void DNF_sort(int a[], int n){
    int low=0, mid=0;
    int high=n-1;
    while(mid<=high){
        if (a[mid]==0)
        {   swap(a[low],a[mid]);
            low++;
            mid++;
        }
        else if (a[mid]==1)
        {  
            mid++;
        }
        else
        {   
            swap(a[mid],a[high]);
            high--;
        }
        
        
    }
}
int main()
{	int a[]={0,1,2,0,0,1,2,2,1,2};
    int n=10;
    DNF_sort(a,n-1);
    for (int i = 0; i < 10; i++)
    {
        cout<<a[i]<<" ";
    }
    
    return 0;
}