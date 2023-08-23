#include <iostream>
#include<vector>
using namespace std;
//Check if any subarray of size k exist such that elements of that subarray form a number divisible by 3
pair<int,int> Numdivby3(vector<int> a, int n ,int k, int &check){
    int sum=0;
    //first calculate sum of first k elements
    int i;
    for ( i = 0; i < k; i++)
    {
        sum+=a[i];
    }
    // 1233  is divisible as 12 +33 =45 which is divisible by 3 
     if(sum%3==0)
        {   
            check= 1;
             return {0,k-1};
        }
    while ( i<n) //i=k
    {    sum= sum-a[i-k]+a[i];
        if (sum%3==0)
        {   
            check= 1;
             return {i-k+1,i};
        }
     
        i++;
    }
      check=0;
    return {0,-1};
}
int main()
{	vector<int> a={84,23,45,12,56,82};
      int k=3;
      int check=0;
    pair<int,int> ans=Numdivby3(a,a.size(),k,check);
    if (ans.second==-1)
    { cout<<"No such subarray exist"<<endl;
        
    }
    else
    {
        for (int i = ans.first; i <=ans.second; i++)
        { cout<<a[i]<<" ";
            
        }
        
    }
    
    
    return 0;
}