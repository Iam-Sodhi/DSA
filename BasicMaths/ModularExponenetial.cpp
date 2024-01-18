#include <bits/stdc++.h>
using namespace std;
// (x^n)%m
int modularExponential(int x,int n, int m){
    int res=1;

    while(n){
        if(n&1){
            res=(1ll * res *(x)%m)%m;
        }
        x=(1ll* (x)%m * (x)%m)%m;
        n=n>>1;
    }
    return res;
}
int main()
{	 int x=3, n=4;
     int m=10000;
     cout<<modularExponential(x,n,m)<<endl;
    return 0;
}