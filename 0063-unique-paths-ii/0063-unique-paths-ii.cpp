class Solution {
public:
    int solve(vector<vector<int>>&arr,int n,int m,int i,int j,vector<vector<int>>&dp){
        if(i<0||j<0||i>=n||j>=m)return 0;
        if(arr[i][j]==1)return 0;
        if(i==0&&j==0)return 1;
        if(dp[i][j]!=-1)return dp[i][j];
        return dp[i][j]=solve(arr,n,m,i-1,j,dp)+solve(arr,n,m,i,j-1,dp);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& arr) {
        int n=arr.size();
        int m=arr[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return solve(arr,n,m,n-1,m-1,dp);
    }
};