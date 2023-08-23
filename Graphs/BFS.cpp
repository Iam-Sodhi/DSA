#include<iostream>
#include<queue>
#include<vector>
using namespace std;
//******breadh first searching ***** based on queue & like level order traversal
const int N=1e5+1;
bool visited[N];
vector<int> adj[N];  // to make adjacency list

void BFS(int node){
    queue<int> q;
    q.push(node);
    visited[node]=true;  // as visited is global so any change may reflect
    while (!q.empty())
    {
        int n= q.front();
        q.pop();
        cout<<n<<" ";
        
        vector <int> :: iterator it;
        for ( it = adj[n].begin(); it !=adj[n].end(); it++)
        {
            if (!visited[*it])
            {
                q.push(*it);
                visited[*it]=true;
            }
            
        }
        
    }
    
    
}
int main(){
    int n, m;  // n-> no of nodes
    cin>>n>>m; // m-> no of edges
    for (int i = 0; i < n; i++)
    {
        visited[i]=false;
    }
   int x, y;
    for (int j = 0; j < m; j++)  // we travel m times (all the edges )
    {                            // and store the adjacent list
        cin>>x>>y;    
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

//        1
//       / \
//      2   3
//    /|\\   \
//   4 5 6\  |
//         \ |
//          7
    
   int i=1; // we can change that
    BFS(i);
    return 0;
}
