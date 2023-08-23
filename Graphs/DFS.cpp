#include <iostream>
#include <vector>
using namespace std;
//*****Depth First Searching***** --> Based on stack
const int N = 1e5 + 1;
bool visited[N];
vector<int> adj[N]; // to make adjacency list

void DFS(int node)
{
    // preorder
    cout << node << " ";
    visited[node] = true;
    // inorder

    vector<int>::iterator it;
    for (it = adj[node].begin(); it != adj[node].end(); it++)
    {
        if (!visited[*it])
        {
            visited[*it] = true;
            DFS(*it);
        }
    }
}
int main()
{
    int n, m;      // n-> no of nodes
    cin >> n >> m; // m-> no of edges
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    int x, y;
    for (int j = 0; j < m; j++) // we travel m times (all the edges )
    {                           // and store the adjacent list
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    //        1        // n=7 & m(no of edges)=7
    //       / \
    //      2   3
    //    /|\\   \
    //   4 5 6\  |
    //         \ |
    //          7

    int i = 1; // we can change that
    DFS(i);
    return 0;
}
