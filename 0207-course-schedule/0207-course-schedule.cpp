class Solution {
public:
    bool dfs(vector<vector<int>>&adj,vector<bool>&vis,int i,vector<bool>&inRecPath){
        vis[i]=true;
        inRecPath[i]=true;
        for(auto &x:adj[i]){
            if(vis[x]==false){
                if(dfs(adj,vis,x,inRecPath)){
                    return true;
                }
            }else{
                //in rec path true hei matlaab cycle hei
                if(inRecPath[x]==true){
                    return true;
                }
            }
        }
        inRecPath[i]=false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        for(int i=0;i<prerequisites.size();i++){
            int course=prerequisites[i][0];
            int dependent=prerequisites[i][1];
            adj[dependent].push_back(course);
        }
        vector<bool>vis(numCourses,false);
        vector<bool>inRecPath(numCourses,false);
        for(int i=0;i<numCourses;i++){
            if(vis[i]==false){
                if(dfs(adj,vis,i,inRecPath)){
                    return false;
                }
            }
        }
        return true;
    }
};