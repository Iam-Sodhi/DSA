#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// Kruskal's Algorithm *****-> To find the minimum Spanning tree
vector<vector<int>> edges;
void make_set(int n, vector<int> &rank, vector<int> &parent)
{
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }
}
int find_parent(int n, vector<int> &rank, vector<int> &parent)
{
    if (n == parent[n])
    {
        return n;
    }

    return parent[n] = find_parent(parent[n], rank, parent); // Path compression
}
void make_union(int a, int b, vector<int> &rank, vector<int> &parent)
{
    a = find_parent(a, rank, parent);
    b = find_parent(b, rank, parent);
    if (rank[a] < rank[b])
    {
        parent[a] = b;
    }
    else if (rank[a] > rank[b])
    {
        parent[b] = a;
    }
    else if (rank[a] == rank[b])
    {
        parent[a] = b;
        rank[b]++;
        // or parent[b]=a and rank[a]++;
    }
}
int main()
{
    int n, m;      // n-> no of nodes
    cin >> n >> m; // m-> no of edges
    vector<int> rank(n);
    vector<int> parent(n);
    int x, y, w;
       // 4 5
    // 0 1 10
    // 1 2 15
    // 0 2 5
    // 3 1 2
    // 3 2 40
    for (int j = 0; j < m; j++)
    {
        cin >> x >> y >> w;
        edges.push_back({x, y, w});
    }
    make_set(n, rank, parent);

    // Now firstly sort them in ascending order of their weight
    sort(edges.begin(), edges.end());
    int cost = 0;
    for (auto i : edges)
    {
        int a = i[0];
        int b = i[1];
        int c = i[2];
        int x = find_parent(a, rank, parent);
        int y = find_parent(b, rank, parent);
        if (x == y)
        {                // ignore the edges having same component
            continue;
        }

        else
        {   cost+=c;
            make_union(a, b, rank, parent);
        }
    }
   cout<<"The cost of spanning tree is : "<<cost;
    return 0;
}
