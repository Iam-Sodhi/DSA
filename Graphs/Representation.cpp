#include <iostream>
#include<vector>
using namespace std;

int main()
{	int n, m;  // n-> no of nodes and m-> no of edges
   cin>>n>>m;
   int N=1e5+1;
   vector<int> adj[N];
//        1
//       / \
//      2   3
//    /|\\   \
//   4 5 6\  |
//         \ |
//          7
    
   int x,y;
   for (int i = 0; i < m; i++)
   {
    cin>>x>>y;
    adj[x].push_back(y);
    adj[y].push_back(x);
   }
   
   for (int j = 1; j <n+1; j++)
   {
       cout<<j<<" -> ";
     vector<int> :: iterator it;
     for ( it = adj[j].begin(); it !=adj[j].end(); it++)
     {
        cout<<*it<<" ";
     }
     cout<<endl;
   }
   // we can also make adjacent matrix by making 2D vector matrix
   // vector<vector<int>> adm(n+1, vector<int>(n+1,0));
    return 0;
}