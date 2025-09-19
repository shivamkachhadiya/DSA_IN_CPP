class Solution {
public:
int solve(vector<int>&prices,int n,int ind,int buy,vector<vector<int>>&dp){
    if(ind>=n){
        return 0;
    }
    if(dp[ind][buy]!=-1)return dp[ind][buy];
    if(buy){
        return dp[ind][buy]= max(-prices[ind]+solve(prices,n,ind+1,0,dp),
                    0+solve(prices,n,ind+1,1,dp));
    }else{
        return dp[ind][buy]= max(prices[ind]+solve(prices,n,ind+2,1,dp),
                    0+solve(prices,n,ind+1,0,dp));

    }
    
}
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return solve(prices,n,0,1,dp);
    }
};