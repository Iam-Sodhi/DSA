#include <iostream>
using namespace std;
//*****Knapsack-Problem*******-->Put n items with given weight and value in a knapsack of capacity W to get the max total balue in knapsack, Find that value.
//Important problem
int Value_knapsack(int w[], int val[], int W, int n)
{   if (n==0||W==0)
{
    return 0;
}
  if (w[n-1]>W)
  {
    return Value_knapsack(w,val,W,n-1);
  }
  

    return max((Value_knapsack(w, val, W - w[n - 1], n - 1) + val[n - 1]), Value_knapsack(w, val, W, n - 1));
}
int main()
{
    int w[] = {10,20,30};
    int value[]={100,50,150};
    int W=50;
    cout<<Value_knapsack(w,value,W,3);
    return 0;
}