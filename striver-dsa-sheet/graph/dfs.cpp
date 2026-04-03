//https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1

class Solution {
    public:
          
      vector<int> ans;
      
      void myDfs(int node, vector<vector<int>> &adj, vector<bool> &vis){
          vis[node]=true;
          
          ans.push_back(node);
          
          for(auto &neigh:adj[node]){
              if(vis[neigh]==false){
                  vis[neigh]=true;
                  myDfs(neigh, adj, vis);
              }
          }
      }
      
      vector<int> dfs(vector<vector<int>>& adj) {
          // Code here
          int n=adj.size();
          vector<bool> vis(n+1,0);
          myDfs(0,adj, vis);
          return ans;
      }
  };