class Solution {
public:
    int solve(vector<vector<int>>&mat,int m,int n,int i,int j,vector<vector<int>>&dp){
        if(i<0||j<0)return 1e9;
        if(i==0&&j==0)return mat[i][j];
        if(dp[i][j]!=-1)return dp[i][j];
        int leftAns=mat[i][j]+solve(mat,m,n,i,j-1,dp);
        int rightAns=mat[i][j]+solve(mat,m,n,i-1,j,dp);

        return dp[i][j]=min(leftAns,rightAns);
    }
    int minPathSum(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return solve(mat,m,n,m-1,n-1,dp);
    }
};