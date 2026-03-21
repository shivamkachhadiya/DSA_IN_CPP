class Solution {
public:
    int solve(vector<int>&arr,int i,int n,int buy,vector<vector<int>>&dp){
        if(i==n)return 0;
        if(dp[i][buy]!=-1)return dp[i][buy];
        int profit=0;
        if(buy){
            profit=max(-arr[i]+solve(arr,i+1,n,0,dp),0+solve(arr,i+1,n,1,dp));
        }else{
            profit=max(arr[i]+solve(arr,i+1,n,1,dp),0+solve(arr,i+1,n,0,dp));
        }
        return dp[i][buy]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        return solve(prices,0,prices.size(),1,dp);
    }
};