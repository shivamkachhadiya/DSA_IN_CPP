class Solution {
public:
    bool dfs(int node,int numCourses,vector<vector<int>>&prerequisites,vector<vector<int>>&adj,vector<bool>&vis,
            vector<bool>&inRecPath){
        vis[node]=true;
        inRecPath[node]=true;
        
        for(auto &x:adj[node])
        {
            if(vis[x]==false){
                if(dfs(x,numCourses,prerequisites,adj,vis,inRecPath)){
                    return true;
                }
            }else{
                if(inRecPath[x]==true){
                    return true;
                }
            }
        }
        inRecPath[node]=false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
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
                if(dfs(i,numCourses,prerequisites,adj,vis,inRecPath)){
                    return false;
                }

            }
        }
        return true;
    }
};