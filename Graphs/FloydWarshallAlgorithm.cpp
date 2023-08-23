#include <iostream>
#include <vector>
#include <set>
// To find all pair shortest paths. i.e. for every u,v for graph G, find the shortest path form u to v
//  O(n^3) like djikstra Algorithm
// in Dijkstra Algorithm O(n2) for finding for single node and O(n3) to then find for all nodes
using namespace std;
vector<vector<int>> edges;
int main()
{

    const int INF = 1e5;
    vector<vector<int>> graph = {{0, 5, INF, 10},  // here it represents dist of 0 to 0 is 0, ->1=5,->2=INF,->3=10
                                 {INF, 0, 3, INF}, // dist of 1 to 0 is INF, ->1=0,----
                                 {INF, INF, 0, 1},
                                 {INF, INF, INF, 0}};
    vector<vector<int>> dist = graph;
    int n = graph.size();
    for (int k = 0; k < n; k++) // we have taken k=0 here as our nodes will start from 0 otherwise take acc to Q
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
        // Now to print the answer
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (dist[i][j] == INF)
                {
                    cout << "INF"
                         << " ";
                }
                else
                {
                    cout << dist[i][j]<<" ";
                }
            }
            cout << endl;
        }

        return 0;
    }
