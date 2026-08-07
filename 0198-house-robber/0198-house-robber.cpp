class Solution {
public:
    int solve(vector<int>&nums,int n,int i,vector<int>&dp){
        if(i >= n) return 0; // out of bounds
        if(i == n-1) return nums[i]; // last element
        if(dp[i]!=-1)return dp[i];
        int take=nums[i]+solve(nums,n,i+2,dp);
        int nontake=solve(nums,n,i+1,dp);
        return dp[i]=max(take,nontake);
    }
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        return solve(nums,nums.size(),0,dp);
    }
};