class Solution {
public:
    int solve(vector<int>&arr,int n,int i,int prev,vector<vector<int>>&dp){
        if(i>=n)return 0;
        if(dp[i][prev+1]!=-1)return dp[i][prev+1];
        //take
        int take=0;
        if(prev==-1||arr[i]>arr[prev]){
            take=1+solve(arr,n,i+1,i,dp);
        }
        int notake=0+solve(arr,n,i+1,prev,dp);
        return dp[i][prev+1]=max(take,notake);
    }
    int lengthOfLIS(vector<int>& arr) {
        int n=arr.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(arr,n,0,-1,dp);
    }
};