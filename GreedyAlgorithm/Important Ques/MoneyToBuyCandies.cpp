#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
//In a candy store, N diff types of candis available and the prices of all N diff types of candies are provided to you.
//Offer: You can buy a single candy from the store and get at most K other candies (diff types) for free.
//Now find what is the MIINIMUM and MAXIMUM amout of money you have to spend to buy all the N different candies by utilizing the offer.
int main()
{	 int N=4;
     int k=2; 
    vector<int> candies={3,2,1,4};
   // firstly sort
   sort(candies.begin(), candies.end());
    //******For Minimum amout******
    // firstly buy the candies with min price then  get maximum price ones for free
    int buy= 0;
    int free=N-1;
    int ans=0;
    while (buy<=free) 
    {    ans+=candies[buy];
         buy++;
         free-=k;
        
    }
    cout<<"The minimum amount of candies: "<<ans<<endl; // buy 1 get 3&4 FOR FRee then again buy 2 -> 2+1

    //*******For MAXIMUM Amount******
    //firstly buy the candy with max price and get the candies with min price for free
    buy=N-1;
     free=0;
    ans=0;
     while (free<=buy)
     {
        ans+=candies[buy];
        buy--;
        free+=k;
     }
     cout<<"The maximum amount of candies: "<<ans<<endl; 
    
    return 0;
} 