#include <iostream>
using namespace std;
//print all sub_arrays
int main()
{	int n;
    cin>>n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
cout<<endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = i ;j< n; j++)
        {
            for (int k = i; k <= j; k++)
            {
                cout<<a[k]<<" ";
            }
            cout<<endl;
        }
        
    }
    
    return 0;
}