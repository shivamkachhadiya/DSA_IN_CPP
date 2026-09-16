class Solution {
public:
    int solve(vector<int>&arr,int n,int i,vector<int>&dp){
        if(i>=n)return 0;
        if(dp[i]!=-1)return dp[i];
        int take=arr[i]+solve(arr,n,i+2,dp);
        int notake=0+solve(arr,n,i+1,dp);
        return dp[i]=max(take,notake);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,-1);
        return solve(nums,n,0,dp);
    }
};