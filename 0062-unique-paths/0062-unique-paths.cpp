class Solution {
public:
    int solve(int n,int m,int i,int j,vector<vector<int>>&dp){
        if(i<0||j<0)return 0;
        if(i==0&&j==0)return 1;
        if(dp[i][j]!=-1)return dp[i][j];
        return dp[i][j]=solve(n,m,i-1,j,dp)+solve(n,m,i,j-1,dp);
    }
    int uniquePaths(int row, int col) {
        vector<vector<int>>dp(row,vector<int>(col,-1));
        return solve(row,col,row-1,col-1,dp);
    }
};