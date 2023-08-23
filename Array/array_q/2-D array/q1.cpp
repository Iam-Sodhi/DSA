#include <iostream>
using namespace std;
int main()
{	int a[3][4];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j <4; j++)
        {
            cin>>a[i][j];
        }
        
    }
    int num;
    cout<<"Enter the number you want to search:";
    cin>>num;
    int verify=0;
     int ind1,ind2;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (a[i][j]==num)
            {
               verify= 1;
               ind1=i; 
               ind2=j;
               break;
            }
            
        }
        
    }
    if (verify==1)
    {
        cout<<"The Element is found at index "<<ind1<<","<<ind2;
    }
    else
    {
        cout<<"The Element is not found in the array";
    }
    
    return 0;
}    