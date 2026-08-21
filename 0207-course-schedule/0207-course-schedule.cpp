class Solution {
public:
    bool solve(int src,vector<bool>&vis,vector<bool>recPath,vector<vector<int>>&adj){
        vis[src]=true;
        recPath[src]=true;
        for(auto &x:adj[src]){
            if(vis[x]==false){
                if(solve(x,vis,recPath,adj)){
                    return true;
                }
            }else if(recPath[x]==true){
                return true;
            }
        }
        recPath[src]=false;
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& edges) {
        vector<bool>vis(n,false);
        vector<bool>recPath(n,false);
        vector<vector<int>>adj(n+1);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
        }
        for(int i=0;i<n;i++){
            if(vis[i]==false){
                if(solve(i,vis,recPath,adj)){
                    return false;
                }
            }
        }
        return true;

    }
};