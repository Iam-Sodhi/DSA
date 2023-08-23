#include <iostream>
#include<climits> // for INT_MIN and INT_MAX
using namespace std;
int main()
{	int n;
   cout<<"Enter the size of the array:";
   cin>>n;
  int arr[n];
   for (int i = 0; i < n; i++)
   {
    cin>>arr[i];
   }
   
    int max_num=INT_MIN;
    int min_num=INT_MAX;
    for (int i = 0; i <5; i++)
    {
          max_num=max(max_num,arr[i]);
          min_num=min(min_num,arr[i]);
    }
    cout<<max_num<<" "<<min_num;
    return 0;
}