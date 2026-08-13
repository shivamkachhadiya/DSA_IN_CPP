class Solution {
public:
    int solve(vector<int>&coins,int target,vector<int>&dp){
        if(target==0){
            return 0;
        }
        if(target<0){
            return INT_MAX;
        }
        if(dp[target]!=-1)return dp[target];
        int mini=INT_MAX;

        for(int i=0;i<coins.size();i++){
            int ans=solve(coins,target-coins[i],dp);
            if(ans!=INT_MAX){
                mini=min(mini,ans+1);
            }
        }
        return dp[target]=mini;
    }
    int coinChange(vector<int>& coins, int amount) {
        
        int n=coins.size();
        vector<int>dp(amount+1,-1);
        int ans=solve(coins,amount,dp);
        if(ans!=INT_MAX)return ans;
        return -1;
    }
};