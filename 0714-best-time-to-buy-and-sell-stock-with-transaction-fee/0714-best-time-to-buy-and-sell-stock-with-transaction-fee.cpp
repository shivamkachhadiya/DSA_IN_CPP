class Solution {
public:
    int solveDP(int index, int buy, vector<int>& prices, int fees,
                vector<vector<int>>& dp) {
        if (index == prices.size()) {
            return 0;
        }

        if (dp[index][buy] != -1)
            return dp[index][buy];

        int profit = 0;
        if (buy) {
            // Buy or Skip
            dp[index][buy] =
                max(-prices[index] + solveDP(index + 1, 0, prices, fees, dp),
                    0 + solveDP(index + 1, 1, prices, fees, dp));
        } else {
            // Sell or Skip
            dp[index][buy] = max(prices[index] - fees +
                                     solveDP(index + 1, 1, prices, fees, dp),
                                 solveDP(index + 1, 0, prices, fees, dp));
        }
        return dp[index][buy];
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        // return solve(0, 1, prices);
        return solveDP(0, 1, prices, fee, dp);
    }
};