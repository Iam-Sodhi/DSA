#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// Given an array of size N where each value represents the no of chocolate in a packet. Each packet can have a variable no of chocolates.
// There are M students , the task is to distribute packets among students such that:
//  Each student gets exactly one packet.
//  The difference bw maximum no of chocolates given to a student and minimum no of chocolates given to a student is minimum.
//****** We will use Sliding Window Technique here******
int MinDiffernce_DistributeChocolates(vector<int> a,int n,int  m){
    int ans=INT8_MAX;
    //first sort
    sort(a.begin(),a.end());
    //chech for  m packets to be distributed among  total m students
    for (int i = m-1; i < n; i++)
    {  
        int temp=a[i]- a[i-m+1];
        ans=min(ans,temp);
    }
    return ans;
}
int main()
{
    int n = 8, m = 5;
    vector<int> a = {3, 4, 1, 9, 56, 7, 9, 12};
    cout<<MinDiffernce_DistributeChocolates(a,n,m)<<endl;
    return 0;
}