class Solution {
public:
    int solve(vector<int>&arr,int n,int i,int buy,vector<vector<int>>&dp){
        if(i==n)return 0;
        int profit=0;
        if(dp[i][buy]!=-1)return dp[i][buy];
        if(buy){
            int buykaro=-arr[i]+solve(arr,n,i+1,0,dp);
            int skipBuy=solve(arr,n,i+1,1,dp);
            profit=max(buykaro,skipBuy);
        }else{
            int sellkaro=arr[i]+solve(arr,n,i+1,1,dp);
            int skipSell=solve(arr,n,i+1,0,dp);
            profit= max(sellkaro,skipSell);
        }
        return dp[i][buy]=profit;
    }
    int maxProfit(vector<int>& arr) {
        int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return solve(arr,arr.size(),0,1,dp);
    }
};