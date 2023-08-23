#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
//*****IMP Problem **** 
//We will see the space optimization of last problem using the queue
//have space compexibily =O(1) and TC=O(n)
int solve(vector<int> &days, vector<int> &costs){
    queue<pair<int,int>> week; // to store day and min cost  
    queue<pair<int,int>> month;
   
    int ans=0;
    for (int i = 0; i < days.size(); i++)
    {
        //firstly remove the expired days from the queue
        if(!week.empty()&& week.front().first +7 <=days[i])
        week.pop();
        if(!month.empty()&& month.front().first +30 <=days[i])
        month.pop();


        //step2: Add cost of curr element
        week.push({days[i],costs[1]+ans}); // it shows if use this 7-pass then upto that i days, the min cost will become cost[1]+ans 
        //ans stores the min cost of i-1 days
        month.push({days[i],costs[2]+ans});

        //update the ans now
        ans=min(costs[0]+ans,min(week.front().second,month.front().second)); //here FIFO principle of queue is used
        
    }
    return ans;
    
}
int main()
{	vector<int> days = {1,4,6,7,8,20};
    vector<int> costs = {2,7,15};

    cout<<solve(days,costs)<<endl;
    return 0;
}