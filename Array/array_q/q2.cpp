#include <iostream>
using namespace std;
//*****Sum of all sub-arrays******
int main()
{	int arr[3]={1,2,2};
    int num=1;
    for (int i = 0; i < 3; i++)
    {    int curr=0;
        for (int j = i; j < 3; j++)
        {
            curr+=arr[j];
            cout<<"The sum of "<<num<<" sub-array: "<<curr<<endl;
            num++;
        }
        
    }
    
    return 0;
}