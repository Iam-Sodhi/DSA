#include <iostream>
using namespace std;
// transpose of the m square atrix
int main()
{	int a[3][3]={{1,2,3},{4,5,6},{7,8,9}};
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    
   // We need to swap only lower triangle elements with upper triangle
    for (int i = 0; i<3; i++)
    {
         for (int j = 0; j<i; j++)
         {
            int temp= a[i][j];
            a[i][j]=a[j][i];
            a[j][i]=temp;
         }
         
    }
    cout<<endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}