class Solution {
public:
    void solve(vector<vector<char>>&grid,int n,int m,vector<vector<bool>>&vis,int i,int j){
        if(i<0||j<0||i>=n||j>=m||grid[i][j]=='0'||vis[i][j]==true){
            return;
        }
        vis[i][j]=true;
        solve(grid,n,m,vis,i-1,j);
        solve(grid,n,m,vis,i,j+1);
        solve(grid,n,m,vis,i+1,j);
        solve(grid,n,m,vis,i,j-1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int island=0;
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'&&vis[i][j]==false){
                    solve(grid,n,m,vis,i,j);
                    island++;
                }
            }
        }
        return island;
    }
};