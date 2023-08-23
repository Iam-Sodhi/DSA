#include <iostream>
#include <vector>
#include <set>
// It can be used to find the shortest distance of nodes from source node even if the weights are negative
//  It can be used to find negative cycle present
// It is applied to directed graph with negative weights(undirected can be converted into directed)
//  Negattve cycle should not be present
using namespace std;
vector<vector<int>> edges;
int main()
{
    int n, m;      // n-> no of nodes
    cin >> n >> m; // m-> no of edges
    int x, y, w;
//    3 nodes and 3 edges
//    1->2 wt=2
//    2->3 wt=-1
//    1->3 wt=2
// source 1
    for (int j = 0; j < m; j++)
    {
        cin >> x >> y >> w;
        edges.push_back({x, y, w});
    }
    vector<int> dist(n + 1, 1e5);
    // We just need to apply the algorithm n-1 times to find the shortest distance
    //  If even after n-1 passes , the distance array is getting updated on nth pass that means that negative cycle is present
    int source;
    cin >> source;
    dist[source] = 0;
    bool isNegativeCycle=false;
    for (int i = 0; i < n - 1; i++) // n-1 passes
    {
        for (int j = 0; j < m; j++) // finding shortest distance by traversing every edge
        {
            int u = edges[j][0];
            int v = edges[j][1];
            int x = edges[j][2];
            if (dist[u]!=1e5&& dist[u] + x < dist[v]) //dist[u]!=1e5 ->It is just to make it more efficient
            {
                dist[v] = dist[u] + x;
            }
        }
    }
  // Checking if negative cylce in nth pass
  for (int j = 0; j < m; j++) 
        {
            int u = edges[j][0];
            int v = edges[j][1];
            int x = edges[j][2];
            if (dist[u] + x < dist[v])
            {  
               isNegativeCycle=true;
            }
        }
        if (isNegativeCycle)
        {
            cout<<"The negative cycle is present";
        }
        else
        {
       for (int i = source-1; i < n; i++)
       {
        cout<<i<<" ";
       }
       
        }
        
        
    return 0;
}
