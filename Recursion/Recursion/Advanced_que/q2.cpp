#include <iostream>
using namespace std;
//Count the number of paths possible from start point to end point in gameboard
int paths(int s, int e){
    if (s==e)
    {
        return 1;
    }
    if (s>e)
    {
        return 0;
    }
    
    int count=0;
   
    for (int i = 1; i <=6; i++)  // dice 
    {
        count+=paths(s+i,e);
    }
    
    return count;
}
int main()
{	cout<<paths(0,3);
    return 0;
}