#include <iostream>
using namespace std;
// Given a 2*n board and tiles of size 2*1, count the no of ways to tile the given board using these tiles.
int tiling_ways(int n)
{
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }

    return tiling_ways(n - 1) + tiling_ways(n - 2); // it is like fibonnaci series
}
int main()
{ int n;
  cin>>n;
  cout<<tiling_ways(n);
    return 0;
}