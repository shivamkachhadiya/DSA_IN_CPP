class Solution {
public:
    int solve(vector<vector<int>>&grid,int n,int m,int i,int j,vector<vector<int>>&dp){
        if(i==0&&j==0)return grid[i][j]==0?1:0;
        if(i<0||j<0)return 0;
        if(grid[i][j]==1)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        return solve(grid,n,m,i-1,j,dp)+solve(grid,n,m,i,j-1,dp);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return solve(grid,n,m,n-1,m-1,dp);
    }
};