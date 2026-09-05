class Solution {
public:
    bool solve(int n,vector<bool>&vis,vector<vector<int>>&arr,vector<vector<int>>&adj,int start,vector<bool>&isRecPath){
        vis[start]=true;
        isRecPath[start]=true;
        for(auto &p:adj[start]){
            if(vis[p]==false){
                if(solve(n,vis,arr,adj,p,isRecPath)){
                    return true;
                }
            }else if(isRecPath[p]==true){
                return true;
            }
        }
        isRecPath[start]=false;
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(n+1);
        for(auto &x:prerequisites){
            int u=x[0];
            int v=x[1];
            adj[v].push_back(u);
        }
        vector<bool>vis(n,false);
        vector<bool>isRecPath(n,false);
        for(int i=0;i<n;i++){
            if(vis[i]==false){
                if(solve(n,vis,prerequisites,adj,i,isRecPath)){
                    return false;
                }
            }
        }
        return true;
    }
};