class Solution {
public:
    bool dfs(int node,vector<vector<int>>&prerequisites,vector<vector<int>>&adj,vector<bool>&vis,vector<bool>&isRecPath){
        vis[node]=true;
        isRecPath[node]=true;
        for(auto &x:adj[node]){
            if(vis[x]==false){
                if(dfs(x,prerequisites,adj,vis,isRecPath)){
                    return true;
                }
            }else if(isRecPath[x]==true){
                return true;
            }
        }
        isRecPath[node]=false;
        return false;
    }
    bool canFinish(int V, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(V);
        for(int i=0;i<prerequisites.size();i++){
            int u=prerequisites[i][0];
            int v=prerequisites[i][1];
            adj[u].push_back(v);
        }
        vector<bool>vis(V,false);
        vector<bool>isRecPath(V);
        for(int i=0;i<V;i++){
            if(vis[i]==false){
                if(dfs(i,prerequisites,adj,vis,isRecPath)){
                    return false;
                }
            }
        }
        return true;

    }
};