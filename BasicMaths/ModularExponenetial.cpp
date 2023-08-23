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
{	
    return 0;
}