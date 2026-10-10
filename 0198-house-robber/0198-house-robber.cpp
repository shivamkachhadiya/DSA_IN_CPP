class Solution {
public:
    int solve(vector<int>&arr,int i,int n,vector<int>&dp){
        if(i>=n)return 0;
        if(dp[i]!=-1)return dp[i];
        int take=arr[i]+solve(arr,i+2,n,dp);
        int notake=0+solve(arr,i+1,n,dp);
        return dp[i]=max(take,notake);
    }
    int rob(vector<int>& arr) {
        int n=arr.size();
        vector<int>dp(n,-1);
        return solve(arr,0,n,dp);
    }
};