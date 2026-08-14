class Solution {
public:
    int solve(int row,int col,int i,int j,vector<vector<int>>&dp){
        if(i < 0 || j < 0) return 0;

        if(i==0&&j==0)return 1;
        if(dp[i][j]!=-1)return dp[i][j];
        int up=solve(row,col,i-1,j,dp);
        int down=solve(row,col,i,j-1,dp);
        return dp[i][j]=up+down;
    }
    int uniquePaths(int m, int n) {
        int row=m;
        int col=n;
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return solve(row,col,row-1,col-1,dp);
    }
};