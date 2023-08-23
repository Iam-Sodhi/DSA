#include <iostream>
using namespace std;
//Numbers in decreasing or increasing order
void dec(int n){
    if (n==0)
    {
        return ;
    }
    cout<<n<<" ";
    dec(n-1);
    
}
void inc(int n){
    if (n==0)
    {
        return ;
    }
    inc(n-1);
    cout<<n<<" ";
}
int main()
{	int n=20;
    dec(n);
    cout<<endl;
    inc(n);
    return 0;
}