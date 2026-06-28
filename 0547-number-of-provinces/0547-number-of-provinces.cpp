class Solution {
public:
    int ans=0;
    void dfs(int i,vector<vector<int>>& isConnected,vector<bool>&vis,int n){
        vis[i]=true;
        for(int j=0;j<n;j++){
            if(isConnected[i][j]==1&&vis[j]==false){
                vis[j]=true;
                dfs(j,isConnected,vis,n);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<bool>vis(n,false);
        for(int i=0;i<n;i++){
            if(vis[i]==false){
                vis[i]=true;
                dfs(i,isConnected,vis,n);
                ans++;
            }
        }
        return ans;
    }
};