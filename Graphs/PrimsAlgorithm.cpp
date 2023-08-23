#include <iostream>
#include <vector>
using namespace std;
const int N = 1e+5;
vector<pair<int, int>> adj[N];
int main()
{
    int n, m;
    cin >> n >> m;
    int x, y, w; // w->weight
    // 4 5
    // 0 1 10
    // 1 2 15
    // 0 2 5
    // 3 1 2
    // 3 2 40
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y >> w;
        adj[x].push_back({y, w});
        adj[y].push_back({x, w});
    }
    vector<int> key(n + 1);
    vector<bool> mst(n + 1);
    vector<int> parent(n + 1);
    int cost=0;
    for (int i = 0; i <= n; i++)
    {
        key[i] = INT8_MAX;
        mst[i] = false;
        parent[i] = -1;
    }
  
    key[0] = 0; //OUR GRAPH HAS 0 HENCE WE CAN START FROM 0
    parent[0] = -1;
    for (int i = 0; i <= n; i++)
    {
        int min = INT8_MAX;
        int u;
        // Finding the minimum weight wali node
        for (int j = 0; j <= n; j++)
        {
            if (mst[j] == false && key[j] < min)
            {
                u = j;
                min = key[j];
                //cost+=key[u];
            }
            
            // making thst node in mst to be true
            mst[u] = true;
            // updating the parent by checking its adjecent nodes
            for (auto it : adj[u])
            {
                int s = it.first;
                int t = it.second;
                if (mst[s] == false && t < key[s])
                {
                    key[s] = t;
                    parent[s] = u;
                }
            }
        }
    }
    //******
    // vector<pair<pair<int,int>,int>> result;
    // for (int i = 1; i <=n; i++)  // not starting from 0 as parent[0]=-1
    // {
    //     result.push_back({{parent[i],i},key[i]});
    // }
    for (int i = 0; i < n; i++)
    {
        cost+=key[i];
    }
    
  cout<<cost<<endl;
  return 0;
}