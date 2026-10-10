class Solution {
public:
    int solve(vector<vector<int>>&arr,int i,int j,int n,int m,vector<vector<int>>&dp){
        if(i==0&&j==0)return arr[0][0];
        if(i<0||j<0)return 1e9;
        if(dp[i][j]!=-1)return dp[i][j];
        int up=arr[i][j]+solve(arr,i-1,j,n,m,dp);
        int left=arr[i][j]+solve(arr,i,j-1,n,m,dp);

        return dp[i][j]=min(up,left);
    }
    int minPathSum(vector<vector<int>>& arr) {
        int n=arr.size();
        int m=arr[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));

        return solve(arr,n-1,m-1,n,m,dp);
    }
};