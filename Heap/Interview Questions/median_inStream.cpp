#include <iostream>
#include <vector>
#include <queue>
using namespace std;
// Given that integers are read from a data structure. Find the median of the elements read so far .
// Median is the middle value in an ordered list. If the size of the list is even there is no middle value. So the medium is the floor of the average of the two middle classes.
// Brute force- first sort the array(using Insertion sort as we need to add element in run) then find the median (if n=odd -> a[n/2] , if n=even -> a[n-1/2]+a[n+1/2]/2)
// Or we could use heap method here
int signum(int a, int b)
{
    if (a == b)
    {
        return 0;
    }
    else if (a > b)
    {
        return 1;
    }

    else
    {
        return -1;
    }
}
void callMedian(int element, priority_queue<int> &maxheap, priority_queue<int, vector<int>, greater<int>> &minheap, int &median)
{
    int t = signum(maxheap.size(), minheap.size());
    switch (t)
    {
    case 0: // means there are even elements & both maxheap and minheap have same no, hence new element can be added to any of them according to its value
        if (element > median)
        {
            minheap.push(element);
            median = minheap.top();
        }
        else
        {
            maxheap.push(element);
            median = maxheap.top();
        }
        break;
    case 1: // here maxheap has n and minheap has n-1, hence new element is such that diff bw there ******size does not exceed 1*****
        if (element > median)
        {
            minheap.push(element);
            median = (minheap.top() + maxheap.top()) / 2; // now becomes even elements hence median is the average
        }
        else
        {
            // We can't directly push it in maxheap as we need to make sure ******size does not exceed 1*****
            // First remove the element from maxheap and add it to minheap
            minheap.push(maxheap.top());
            maxheap.pop();
            // Now add the element to maxheap
            maxheap.push(element);
            median = (minheap.top() + maxheap.top()) / 2;
        }
        break;
    case -1: // here reverse the above  procedure accordingly as maxheap has n-1 and minheap has n elements
        if (element > median)
        {
            maxheap.push(minheap.top());
            minheap.pop();
            minheap.push(element);
            median = (minheap.top() + maxheap.top()) / 2;
        }
        else
        {
            maxheap.push(element);
            median = (minheap.top() + maxheap.top()) / 2;
        }

        break;
    }
}
vector<int> Median(vector<int> arr)
{
    vector<int> ans;
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int median = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        callMedian(arr[i], maxHeap, minHeap, median); // they are passed ****** by reference****** here
        // Median value will get updated in above function( call by reference)
        ans.push_back(median);
    }
    return ans;
}
int main()
{
    vector<int> a = {2, 1, 4};    
    vector<int> ans = Median(a);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    // here our ordered list keeps on changing when we add the new element
   // here when first element added,  median of ordered list [2]=2
   // when second element added,  median of ordered list [1,2]= floor((1+2)/2)=1
   // when third element added,  median of ordered list [1,2,4]= 2
  
}