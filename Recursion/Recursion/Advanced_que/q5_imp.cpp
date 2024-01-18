#include <iostream>
using namespace std;
//*****Friends pairing problem*****->Find the no of ways in which n friends can remain single or can be paired up.
int pairing_ways(int n)
{ 
     if (n==0||n==1||n==2)
     {
        return n;
     }
     
    return pairing_ways(n - 1) + (n - 1) * pairing_ways(n - 2); // (n-1) when he is not paired; (n-2) when he is  paired with any particular person and that person is chosen from n-1 persons
}
int main()
{  int n;
   cin>>n;
   cout<<pairing_ways(n);

    return 0;
}