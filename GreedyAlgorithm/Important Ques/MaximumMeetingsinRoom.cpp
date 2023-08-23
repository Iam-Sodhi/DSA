#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
//******Important*******
//There is one room in a firm. There are N meetings in the form start[i] (start time of meeting) & end[]( finish time of meeting i.)
//What is the maximum number of meetings that can be accomodated in the room when only meeting ccan be held in the room at particular time.
//NOTE: Start time of one chosen meeeting can't be equal to end time of other chosen meeeting
bool compare(pair<int,int> a, pair<int,int> b){
    return a.second < b.second;
}
int main()
{	int N=6;
    int start[]={1,3,0,5,8,4};
    int end[]={2,4,6,7,9,9};
    vector<pair<int,int> > meeting;
    for (int i = 0; i < N; i++)
    {
        meeting.push_back({start[i],end[i]});
    }
    //Now to get maximum meeting, sort the meeting wrt to end time
    sort(meeting.begin(), meeting.end(),compare);
    
    vector<pair<int,int>> ans;
    ans.push_back({meeting[0]});
    int ansEnd= meeting[0].second;
    for (int i = 1; i < N; i++)
    {  
        if (meeting[i].first>ansEnd) //hence it possible to have another meeting
        {
            ans.push_back(meeting[i]);
            ansEnd= meeting[i].second;
        }
        
    }
    
    cout<<"The Max No of Meetings: "<<ans.size()<<endl;
    for(auto i: ans){
        cout<<i.first<<" "<<i.second<<endl;
    }
    return 0;
}