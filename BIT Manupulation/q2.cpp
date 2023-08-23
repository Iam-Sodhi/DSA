#include <iostream>
using namespace std;
// to count the !'s in the binary of the number
int count_1s(int n){
   // (n&n-1) has same bits as n except the rightmost set bit
   int count=0;
   while (n)  // here n &n-1  is 0 when n is the power of 2
   {
      n=(n&n-1);
      count++;
   }
   return count;
}
int main()
{	 cout<<count_1s(5)<<endl;
    cout<<'5'-'0';
    return 0;
}