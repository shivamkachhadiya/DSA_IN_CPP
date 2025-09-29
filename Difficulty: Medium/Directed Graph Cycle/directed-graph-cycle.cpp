#include<unordered_map>
#include<list>
class Solution {
  public:
      bool checkCycleDFS(int node, unordered_map<int,bool>&visited,
        unordered_map<int,bool>&dfsVisited,
        unordered_map<int,list<int>>&adj){
            visited[node]=true;
            dfsVisited[node]=true;
            
            for(auto neighbour:adj[node]){
                if(!visited[neighbour]){
                    bool cycleDetced=checkCycleDFS(neighbour,visited,dfsVisited,adj);
                    if(cycleDetced)return true;
                }else if(dfsVisited[neighbour]){
                    return true;
                     
                }
            }
            dfsVisited[node]=false;
            return false;
        }
           
  
  
  
    bool isCyclic(int n, vector<vector<int>> &edges) {
        // code here
        unordered_map<int,list<int>>adj;
        for(int i=0;i<edges.size();i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        }
        
        //call dfs for all componeners
        unordered_map<int,bool>visited;
        unordered_map<int,bool>dfsVisited;
        for(int i=1;i<=n;i++){
            if(!visited[i]){
            bool cycleFound = checkCycleDFS(i, visited, dfsVisited, adj);
            if(cycleFound) return true;
            }
        }
        return false;
    }
};