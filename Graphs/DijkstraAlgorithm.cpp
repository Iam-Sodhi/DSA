#include <iostream>
#include <vector>
#include <set>
// Find the single source shortest path from a vertex u to all the vertices in the graph. If the node is unreachable then print -1.
using namespace std;
const int N = 1e5;
vector<vector<pair<int, int>>> edges(N);

int main()
{
    int n, m;      // n-> no of nodes
    cin >> n >> m; // m-> no of edges
    int x, y, w;
    // 4 5
    // 0 1 5
    // 0 2 8
    // 1 2 9
    // 1 3 2
    // 1 2 6
    // Taking 0 as source
    for (int j = 0; j < m; j++)
    {
        cin >> x >> y >> w;
        edges[y].push_back({x, w});
        edges[x].push_back({y, w}); // This algorithm works for both undirected and directed
    }
    vector<int> dist(n, INT16_MAX);
    int source;
    cin >> source;
    dist[source] = 0;
    set<pair<int, int>> s;
    s.insert({dist[source], source}); // pair is like distance , node
    while (!s.empty())
    {
        // Fetch the top record( )
        auto top = *(s.begin());

        int nodedist = top.first;
        int topnode = top.second;
        // Remove top record now
        s.erase(s.begin());
        // traverse on neighbours
        for (auto neighbour : edges[topnode])
        {
            if (nodedist + neighbour.second < dist[neighbour.first])
            { //
                auto record = s.find({dist[neighbour.first], neighbour.first});
                // if record found, then removing it
                if (record != s.end())
                {
                    s.erase(record);
                }
                // distance update
                dist[neighbour.first] = nodedist + neighbour.second;
                // push record in set
                s.insert({dist[neighbour.first], neighbour.first});
            }
        }
    }
    for (int i = source; i < n; i++) // here start form 0 as in question first element is 0
    {
        cout << dist[i] << " ";
    }

    return 0;
}
