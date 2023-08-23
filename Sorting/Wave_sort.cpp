#include <iostream>
using namespace std;
void swap(int c[],int a, int b){
    int temp=c[a];
    c[a]=c[b];
    c[b]=temp;
}
void wave_sort(int a[],int n){
    for (int i = 1; i < n; i+=2)
    {
        if (a[i]>a[i-1])
        { swap(a,i,i-1);
        }
        if (a[i]>a[i+1]&& i<n-1)
        {
            swap(a,i,i+1);
        }
        
    }
    
}
int main()
{	int a[]={3,5,1,6,8,9,2};
   wave_sort(a,7);
    for (int i = 0; i < 7; i++)
    {
        cout<<a[i]<<" ";
    }
    
    return 0;
}