#include <iostream>
#include <vector>
using namespace std;
//*****DSU***** ->Using Path compression and Union by rank then time complexibility -> O(aplha(N)) and space complexibilty->O(n)
//Used in cycel detection and finding connected components
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
    int x, y;
    // 4 4-> {{0,1},{1,2},{2,3},{3,0}}
    for (int j = 0; j < m; j++)
    {
        cin >> x >> y;
        edges.push_back({x, y});
    }
    make_set(n, rank, parent);
    bool cycle = false;
    for (auto i : edges)
    {
        int a = i[0];
        int b = i[1];
        int x=find_parent(a,rank,parent);
        int y=find_parent(b,rank,parent);
        if (x == y)
        {
            cycle = true;
            break;
        }

        else
            {make_union(a, b, rank, parent);}
    }
    if (cycle)
    {
        cout << "The cycle is present";
    }
  

    return 0;
}
