#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
//******For Undirected graph****** -->when visited[node]==true && node!=parent then cycle is present
// We can use both DFS or BFs approach
const int N = 1e+5;
vector<int> adj[N];

bool iscycleBFS(int node, vector<bool> &vis, vector<int> &parent)
{
    parent[node] = -1;
    queue<int> q;
    q.push(node);
    vis[node] = true;
    while (!q.empty())
    {
        int n = q.front();
        q.pop();
        for (auto neighbour : adj[n])
        {
            if (vis[neighbour] == true && parent[neighbour] != n)
            {
                return true;
            }
            else if (!vis[neighbour])
            {

                vis[neighbour] = true;
                parent[neighbour] = n;
                q.push(neighbour);
            }
        }
    }
    return false;
}
// I think DFS is more simpler
bool iscycleDFS(int node, int parent_, vector<bool> &vis)
{
    vis[node] = true;
    for (auto neighbour : adj[node])
    {
        if (!vis[neighbour])
        {
            bool answer = iscycleDFS(neighbour, node, vis);
            if (answer)
            {
                return true;
            }
        }
        else if (neighbour != parent_) // vis[neighbour] == true -->no need to write // It tacke case !-2 is not a cycle
        {
            return true;
        }
    }
    return false;
}
int main()
{
    int n, m;
    cin >> n >> m;

    vector<bool> vis(n, false);
    vector<int> parent(n);
    // 3 nodes such that edges={{1,2},{2,3},{1,3}}
    // oe 4 nod3s such that ={{0,1},{1,2},{2,0}}
    int x, y;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for (int i = 0; i < n; i++) // to handle disconnected components
    {
        if (vis[i] == false)
        {
            bool ans = iscycleBFS(i, vis, parent);
            // bool ans = iscycleDFS(i, -1, vis);
            if (ans)
            {
                cout << "It is cyclic";
                return 1;
            }
        }
    }

    return 0;
}