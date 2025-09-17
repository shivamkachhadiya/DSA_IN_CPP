class Solution {
public:
    int solveDP(int index, int buy, vector<int>& prices,
                vector<vector<vector<int>>>& dp, int limits) {
        if (index == prices.size() || limits == 0) {
            return 0;
        }

        if (dp[index][buy][limits] != -1)
            return dp[index][buy][limits];

        int profit = 0;
        if (buy) {
            // Buy or Skip
            profit = max(-prices[index] + solveDP(index + 1, 0, prices, dp, limits),
                         0 + solveDP(index + 1, 1, prices, dp, limits));
        } else {
            // Sell or Skip
            profit = max(prices[index] + solveDP(index + 1, 1, prices, dp, limits - 1),
                         0 + solveDP(index + 1, 0, prices, dp, limits));
        }

        return dp[index][buy][limits] = profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        // dp[n][2][3] initialized with -1
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k + 1, -1)));
        return solveDP(0, 1, prices, dp, k);
    }
};