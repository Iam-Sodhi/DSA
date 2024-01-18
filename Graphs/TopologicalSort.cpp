#include <iostream>
#include<vector>
#include<stack>
using namespace std;
//In directed graph for each edge from A to B, node a appears before B in the ordering
//*****Only Directed Acyclic Graph****** can have topological sort (using DFS)
//They are not unique
  const int N=1e+5;
  vector<int> adj[N];
void topological_sort(int node,stack<int> &st,bool vis[]){
    vis[node]=true;
    vector<int>:: iterator it;
    for ( it = adj[node].begin(); it !=adj[node].end(); it++)
    {  if (!vis[*it])
    {
        topological_sort(*it,st,vis);
        vis[*it]=true; 
    }
       
    }
    st.push(node);
    
}
//   // degrees keeps tack of items
//         // group degrees keep track of a particular groups degrees
//         vector<int> degrees(n, 0), groupDegree(m, 0);
//          for(int i=0;i<n;i++){
//              for(auto t: beforeItems[i]){
//                  //t->i
//                  graphItem[t].push_back(i);
//                  degrees[i]++;
//                  //now if there groups are not same then we also need to do like groupA->groupB
//                  if(group[i]!=group[t]){
//                      graphGroup[group[t]].push_back(group[i]);
//                      groupDegree[group[i]]++;
//                  }
//              }
//          }
//  vector<int> topologicalSort(vector<vector<int>>& graph,vector<int>& degrees){
//      queue<int> q;
//      vector<int> ans;
//      //firstly check for items with 0 degree
//      for(int i=0;i<degrees.size();i++){
//          if(degrees[i]==0) q.push(i);
//      }
//      while(!q.empty()){
//          int t=q.front();
//          q.pop();
//          ans.push_back(t);
//          for(auto i: graph[t]){
//              degrees[i]--;
//              if(degrees[i]==0){
//                  q.push(i);
//              }
//          }
//      }
//       // if the whole graph could be sorted (no cycles) return its sorted order
//             // if not return an empty vector signifying the top sort could not be ran
//             return (ans.size()==graph.size())?ans: vector<int>();
//  }
int main()
{	int n, m;

    cin>>n>>m;
    
    bool vis[N]={false};
  

    //  //4 nodes and 3 edges ->         
    //  //0 ->1 , 1->2, 2->3               
    //                                  
       int x,y;                        
    for (int i = 0; i < m; i++) {
        cin>>x>>y;
        adj[x].push_back(y);
    }
    stack<int> st;
   
    for (int i = 0; i < n; i++)
    {    
        
         if (vis[i]==false)
         {
             topological_sort(i,st,vis); 
         }
         
    }
    
     //Storing the stack in result array
     vector<int> ans;
     while (!st.empty())
     {  cout<<st.top()<<" ";
        st.pop();
     }
    
     
    return 0;
}