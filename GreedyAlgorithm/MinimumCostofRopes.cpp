#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
// There are given n ropes of diff lengths, we need to connect these ropes into  one rope.
// The cost to connect two ropes is sum of their lengths.
// The task is to connect the ropes with minimum cost

int minCost(vector<int> a, int n)
{
    // our approach is like firstly joining the two shortest ropes
    // for that if use sorting then we will need to do it after every summing the two ropes
    // We will use heap methods here  to get efficient approach O(1)

    priority_queue<int, vector<int>, greater<int>> mini;
    // firstly push the elements into min heap
    for (int i = 0; i < a.size(); i++)
    {
        mini.push(a[i]);
    }
   int cost=0;
    // Now pop first 2 elements from min heap and add them adn then push it back
    while (mini.size() > 1)
    {   int add=0;
        int a = mini.top();
        mini.pop();
        int b = mini.top();
        mini.pop();
         add = a + b;
         cost+=add;
        mini.push(add);
    }
    return cost;
}
int main()
{
    int n = 4;
    vector<int> a = {4, 3, 2, 6};

 cout<<minCost(a,n)<<endl;
    return 0;
}