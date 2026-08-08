class Solution {
public:
    bool dfs(vector<bool>&vis,int n,vector<vector<int>>&nc,vector<vector<int>>&adj,vector<bool>&recPath,int node){
        vis[node]=true;
        recPath[node]=true;
        for(auto &x:adj[node]){
            if(vis[x]==false){
                //dfs
                if(dfs(vis,n,nc,adj,recPath,x)){
                    return true;
                }
            }else if(recPath[x]==true){
                return true;
            }
        }
        recPath[node]=false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if(prerequisites.empty())return true;
        vector<vector<int>>adj(numCourses);
        for(int i=0;i<prerequisites.size();i++){
            int u=prerequisites[i][0];
            int v=prerequisites[i][1];
            adj[v].push_back(u);
        }
        vector<bool>vis(numCourses,false);
        vector<bool>inRecPath(numCourses,false);
        for(int i=0;i<numCourses;i++){
                if(vis[i]==false){
                    if(dfs(vis,numCourses,prerequisites,adj,inRecPath,i)){
                    return false;
                }
            }
        }
        return true;   
    }
};