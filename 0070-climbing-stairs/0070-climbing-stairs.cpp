class Solution {
public:
    int solve(int n,int i,vector<int>&dp){
        if(i>n)return 0;
        if(i==n)return 1;
        if(dp[i]!=-1)return dp[i];
        return dp[i]=solve(n,i+1,dp)+solve(n,i+2,dp);
    }
    int climbStairs(int n) {
        vector<int>dp(n,-1);
        return solve(n,0,dp);
    }
};