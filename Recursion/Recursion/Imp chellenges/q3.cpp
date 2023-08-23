#include <iostream>
using namespace std;
//Tower of Hanoi
 void towerofHanoi(int n, char src, char helper, char dest){
    if (n==0)
    {
        return ;
    }
    
    towerofHanoi(n-1,src,dest,helper);
    cout<<"Move from "<<src<<" to "<<dest<<endl;
    towerofHanoi(n-1,helper,src,dest);
 }
int main()
{	 towerofHanoi(3,'S','H','D');
    return 0;
}