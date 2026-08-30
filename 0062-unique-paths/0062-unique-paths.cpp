class Solution {
public:
    int solve(int row,int col,int i,int j,vector<vector<int>>&dp){
        if(i==0&&j==0)return 1;
        if(i<0||j<0)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        return dp[i][j]=solve(row,col,i,j-1,dp)+solve(row,col,i-1,j,dp);
        
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return solve(m-1,n-1,m-1,n-1,dp);
    }
};