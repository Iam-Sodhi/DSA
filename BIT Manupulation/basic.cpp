#include <iostream>
using namespace std;
int get_bit(int n, int pos) // to see if the bit is 0 or 1 at given position
{
    return ((n & (1 << pos)) != 0);
}

int set_bit(int n, int pos) // it sets the bit at that position equal to 1
{
    return (n | (1 << pos));
}
int clear_bit(int n, int pos) // it is to make the bit at that position equals to zero
{
    int mask = ~(1 << pos);
    return (n & mask);
}
int update_bit(int n, int pos, int val) // it comabination of clear and set_bit or  it is to update the bit at that position to the given val(0 or 1)
{
    int mask = ~(1 << pos);
    n = (n & mask); // it is now cleared

    return (n | (val << pos)); // here the given value(0 or 1) can be set
}
int main()
{
    int pos = 1;
    cout << get_bit(5, pos) << endl; // here pos is like index as first position starts from 0,1,2,---
    cout << set_bit(5, pos) << endl;
    cout << clear_bit(7, pos) << endl;
    cout << update_bit(5, pos, 1) << endl;
    return 0;
}