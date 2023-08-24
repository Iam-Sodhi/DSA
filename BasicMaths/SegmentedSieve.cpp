#include <bits/stdc++.h>
using namespace std;
int main()
{	
    int low;
    int high;

    
    vector<int> primes;
    vector<int> isPrime(sqrt(high),true);
    //firstly get the prime numbers upto sqrt(high)
    for (int i = 2; i <=sqrt(high); i++)
    {   if(isPrime[i]) primes.push_back(i);
        for (int j = i*i; j <=sqrt(high); j+=i)
        {
            isPrime[j]=false;
        }
    }
     
     //make a dummy array
    vector<bool> dummy(high-low+1,true);
    for(auto p: primes){
        int first_multiple=(low/p)*p;   //to get the first multiple in the range [low-high]
        if(first_multiple<low) first_multiple+=p; //to make it first multiple 
        for (int i = max(first_multiple,p*p); i <=high; i+=p)
        {
            dummy[i-low]=false;
        }
        
    }
    
    for (int i = low; i <=high; i++)
    {
        if(dummy[i-low]) cout<<i<<" ";
    }
    
    
    return 0;
}