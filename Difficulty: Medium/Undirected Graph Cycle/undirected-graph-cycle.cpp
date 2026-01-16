class Solution {
  public:
    bool isCyclicDFS(int node,int parent,unordered_map<int,bool>&visited,
    vector<vector<int>> &adj){
        visited[node]=true;
        for(auto nbs:adj[node]){
            if(!visited[nbs]){
                bool cycle=isCyclicDFS(nbs,node,visited,adj);
                if(cycle){
                    return true;
                }
            }else if(nbs!=parent){
                return true;
            }
        }
        return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>> adj(V);

        // Build adjacency list
        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        unordered_map<int,bool>visited;
        for(int i=0;i<V;i++){
            if(!visited[i]){
                bool ans=isCyclicDFS(i,-1,visited,adj);
                if(ans==1){
                    return true;
                }
            }
        }
        return false;
    }
};