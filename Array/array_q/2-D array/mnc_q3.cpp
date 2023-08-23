#include <iostream>
using namespace std;
//Searching the matrix in which rows and columns are sorted
int main()
{	int n,m;
    cin>>n>>m;
    int target;
    cin>>target;
    int a[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin>>a[i][j];
        }
        
    }
    int r=0, c=m-1;
    bool flag= false;
    while (r<n&& c>=0)
    {
        if (target==a[r][c])
        {
            flag =true;
        }
        if (target<a[r][c])
        {
            c--;
        }
        else
        {
            r++;
        }
        
        
    }
    if (flag)
    {
        cout<<"Element found"<<endl;
    }
    else
    {
        cout<<"Element not found"<<endl;
    }
    
    
    return 0;
}