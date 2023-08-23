#include <iostream>
#include <queue>
using namespace std;
int main()
{
    priority_queue<char> pq; //by default it is maxHeap
    pq.push('e');
    pq.push('f');  // lowercase has higher Ascii value
    pq.push('F');
    pq.push('a');
    cout<<"Element at top: "<<pq.top()<<endl;
    pq.pop();
    cout<<"Element at top: "<<pq.top()<<endl;
    pq.pop();
    cout<<"Size: "<<pq.size()<<endl;
    cout<<"pq is empty(0) or not(1): "<<pq.empty()<<endl;
    //For minHeap
    priority_queue<int, vector<int> , greater<int>> minheap;
    minheap.push(1);
    minheap.push(3);
    minheap.push(4);
    minheap.push(2);
    cout<<"Element at top: "<<minheap.top()<<endl;
    minheap.pop();
    cout<<"Element at top: "<<minheap.top()<<endl;
    minheap.pop();
    return 0;
}