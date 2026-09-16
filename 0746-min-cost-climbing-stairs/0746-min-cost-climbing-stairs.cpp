class Solution {
public:
    int solve(vector<int>&arr,int n,int i,vector<int>&dp){
        if(i==n)return 0;
        if(i>n)return 0;
        if(dp[i]!=-1)return dp[i];
        int oneStep=arr[i]+solve(arr,n,i+1,dp);
        int twoStep=arr[i]+solve(arr,n,i+2,dp);

        return dp[i]=min(oneStep,twoStep);
        
    }
    int minCostClimbingStairs(vector<int>& arr) {
        vector<int>dp(arr.size()+1,-1);
        return min(solve(arr,arr.size(),0,dp),solve(arr,arr.size(),1,dp));
    }
};