#include <iostream>
#include <vector>
using namespace std;
//*****Graph does not contain any odd-length cycles
// The graph is 2 colorable
const int N = 1e5 + 1;
vector<int> adj[N];
bool bipartite = true;
void add_color(int node, int col, vector<int> &color, vector<bool> &vis)
{
    if (color[node] != -1 && color[node] != col)
    {
        bipartite = false;
        return;
    }
    color[node] = col;
    if (vis[node])
    {
        return;
    }

    vis[node] = true;
    for (auto neighbour : adj[node])
    {
            add_color(neighbour, col xor 1, color, vis); // 0 xor1 is 1 and  1 xor 1 is 0
       
    }
}
int main()
{
    int n, m;      // n-> no of nodes
    cin >> n >> m; // m-> no of edges
    vector<bool> vis(n, false);
    int x, y;
    // 3 3-> {{0,1},{1,2},{0,2}}      -> non-bipartite (as odd cycle)
    // 4 4-> {{0,1},{1,2},{2,3},{3,0}} -> bipartite (as even cycle)
    for (int j = 0; j < m; j++)
    {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<int> color(n, -1);
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            add_color(i, 0, color, vis);
        }
    }
    if (bipartite)
    {
        cout << "It is bipartite";
    }
    else
    {
        cout << "It is not bipartite";
    }

    return 0;
}
