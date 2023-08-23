#include <iostream>
using namespace std;
// find whether is the number a power of 2
// for this Question, we can also see if we get 1 by dividing the number by 2 again & again but here we will use BIT manipulation
bool Powerof2(int n)
{
    return (n && !(n & n - 1)); // n && -> to tackle the base case when n=0 (we can't access n-1) 
}
int main()
{ // *****(n & n-1) has same bits as n, except the rightmost set bit( ***set bit*** not 0 wali bit)
    // n=8-> 1000
    // n=7-> 0111
    // 8&7 ->0000
    int n = 16;
    cout << Powerof2(n);
    return 0;
}