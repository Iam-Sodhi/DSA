#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
// Find the no of and size of connected components (we will use DFS approach)
//There are N friends numbered from 0 to N-1. Find the no ways in which 2 people from diff groups can be chosen such that they are not related to each other.
const int N = 1e+5;
vector<int> adj[N];
int connected_comp(int n, vector<bool> &vis)
{
    // if (vis[n])
    // {
    //    return 0;
    // }

    vis[n] = true;
    int ans = 1;
    for (auto neighbour : adj[n])
    {
        if (vis[neighbour] == false)
        {
            ans += connected_comp(neighbour, vis);
            vis[neighbour] = true;
        }
    }
    return ans;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<bool> vis(n, false);
    vector<int> component;
    // 5 nodes->{ {0,1},{2,3},{0,4}}; --> has 2 components one of size 3 and other of 2
    int x, y;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            component.push_back(connected_comp(i, vis));
        }
    }

    for (auto it : component)
    {
        cout << it << " ";
    }
    cout<<endl;
    // Now find the no of ways
    // 5 3
    // 0 1
    // 2 3 0 4    
    //It has 6 total_ways
    long total_waysinto2=0;
    for(auto i: component){
        total_waysinto2+= i * (n-i);  // using P&C
    }
    cout<<total_waysinto2/2<<endl; //*****as 2-3 & 3-2 have been couted uniquely in total_ways
    return 0;
}