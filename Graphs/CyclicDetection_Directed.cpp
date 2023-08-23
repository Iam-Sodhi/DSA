#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
//******For directed graph******  //****DON'T USE UNDIRECTED APPROACH******
// We can use both DFS or BFs approach

//*****Also a method to solve for question in which we have to return the safe nodes of the Graph. A node is a terminal node if there are no outgoing edges.
//A node is a safe node if every possible path starting from that node leads to a terminal node (or another safe node).
//nodes part of a cycle are not safe nodes others are
//***** Also to solve Couse schedule  You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.
//Return true if you can finish all courses. Otherwise, return false.

const int N = 1e+5;
vector<int> adj[N];
// if vis[node] && visDFS[node]== true then cycle is present
bool iscycleDFS(int node, int parent, vector<bool> &vis, vector<bool> &DFSvis)
{
    vis[node] = true;
    DFSvis[node] = true;
    for (auto neighbour : adj[node])
    {
        if (!vis[neighbour])
        {
            bool answer = iscycleDFS(neighbour, node, vis, DFSvis);
            if (answer)
            {
                return true;
            }
        }
        else if (DFSvis[neighbour])
        {
            return true;
        }
    }
   DFSvis[node]=false;
    return false;
}
int main()
{
    int n, m;
    cin >> n >> m;

    vector<bool> vis(n, false);
    vector<bool> DFSvis(n, false);
    vector<int> parent(n);
    // oe 4 nodes such that ={{0,1},{1,2},{2,1}}
    int x, y;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        adj[x].push_back(y);
    }
    for (int i = 0; i < n; i++) // to handle disconnected components
    {
        if (vis[i] == false)
        {

            bool ans = iscycleDFS(i, -1, vis, DFSvis);
            if (ans)
            {
                cout << "It is cyclic";
                return 1;
            }
         
            
        }
    }

    return 0;
}