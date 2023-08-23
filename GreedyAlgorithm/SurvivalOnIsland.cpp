#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//Shop opens for all days except Sunday. Consider following constraits:
// N- the max unit of food you can buy each day
//S- no of days you are requied to survive
//M- unit of food required each day to  survive
//Currently,It's Monday and she needs to survive for next 5 days.
//Find the min no of days on which you need to buy food from the shop so that she can survive the next 5 days.
// If it's not possible to survive , return -1

int main()
{	 int S=10;
     int N=16;
     int M=2;
     int ans;
     int sundays= S/7;
     int buyDays= S- sundays;
     if ( (S*M)%N == 0 )
     {
        ans= (S*M)/N;  //S*M ->Total Food
     }
     else
     {
        ans= (S*M)/N +1;  // e.g (2*10)/16 when need extra one day to buy for survival
     }
     
     //Now the chech condition
     //eg if N<M   one can't survive
     // or N=1 and M=1 one would not survive on Sunday (S>6)  // survive no just 5 next days but more
     // S=10 then S*M=10 but (S*M)/N =10 but buying days are =10-10/7=9
      if(ans>buyDays){
        ans=-1;
      }
     cout<<"The minimum no of days one need to buy food to Survive: "<<ans<<endl;
    return 0;
}