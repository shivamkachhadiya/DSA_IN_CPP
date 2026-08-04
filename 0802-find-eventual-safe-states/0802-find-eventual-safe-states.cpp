class Solution {
public:
    vector<int>ans_arr;
    bool dfs(vector<vector<int>>& adj,vector<bool>&vis,vector<bool>&inRecPath,int node){
        vis[node]=true;
        inRecPath[node]=true;

        for(auto &x:adj[node]){
            if(vis[x]==false){
                if(dfs(adj,vis,inRecPath,x))return true;
            }else if(inRecPath[x]==true){
                //cycle here
                
                return true;
            }
        }
        inRecPath[node]=false;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
        int n=adj.size();
        vector<bool>vis(n,false);
        vector<bool>inRecPath(n,false);
        for(int i=0;i<n;i++){
            if(vis[i]==false){
                dfs(adj,vis,inRecPath,i);            
            }
        }
        for(int i=0;i<n;i++){
            if(inRecPath[i]==0){
                ans_arr.push_back(i);
            }
        }
        return ans_arr;
        
    }
};