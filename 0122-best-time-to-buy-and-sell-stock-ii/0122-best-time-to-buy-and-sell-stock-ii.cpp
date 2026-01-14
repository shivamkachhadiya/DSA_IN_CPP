class Solution {
public:
    // int solve(vector<int>&prices,int n,int i,bool buy,int
    // profit,vector<vector<int>>&dp){
    //     if(i==n)return 0;
    //     if(dp[i][buy]!=-1)return dp[i][buy];
    //     if(buy){
    //         profit+=max(-prices[i]+solve(prices,n,i+1,0,profit,dp),
    //                 0+solve(prices,n,i+1,1,profit,dp));
    //     }else{
    //         profit+=max(+prices[i]+solve(prices,n,i+1,1,profit,dp),
    //                 0+solve(prices,n,i+1,0,profit,dp));
    //     }
    //     return dp[i][buy]=profit;

    // }

    int solveDP(vector<int>& prices, int n, vector<vector<int>>& dp) {
    for (int i = n - 1; i >= 0; i--) {
        for (int buy = 1; buy >= 0; buy--) {
            int profit = 0;
            if (buy) {
                profit = max(-prices[i] + dp[i + 1][0],
                             0 + dp[i + 1][1]);
            } else {
                profit = max(+prices[i] + dp[i + 1][1],
                             0 + dp[i + 1][0]);
            }
            dp[i][buy] = profit;
        }
    }
    return dp[0][1];
}

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        return solveDP(prices, n, dp);
    }
};