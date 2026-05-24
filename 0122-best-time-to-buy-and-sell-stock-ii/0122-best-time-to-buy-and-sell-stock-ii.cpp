class Solution {
public:
    int solve(int i, int buy, vector<int>& prices, vector<vector<int>>& dp) {
        if (i == prices.size())
            return 0;
        if (dp[i][buy] != -1)
            return dp[i][buy];
        int profit = 0;

        if (buy) {
            int buykaro = -prices[i] + solve(i + 1, 0, prices, dp);
            int skipkaro = 0 + solve(i + 1, 1, prices, dp);
            profit = max(buykaro, skipkaro);
        } else {
            int sellkaro = +prices[i] + solve(i + 1, 1, prices, dp);
            int skipkaro = 0 + solve(i + 1, 0, prices, dp);
            profit = max(sellkaro, skipkaro);
        }
        return dp[i][buy] = profit;
    }

    int solveTab(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));

        for (int i = n - 1; i >= 0; i--) {
            for (int buy = 0; buy <= 1; buy++) {
               
                int profit = 0;
                if (buy) {
                    int buykaro = -prices[i] + dp[i + 1][0];
                    int skipkaro = 0 + dp[i + 1][1];
                    profit = max(buykaro, skipkaro);
                } else {
                    int sellkaro = +prices[i] + dp[i + 1][1];
                    int skipkaro = 0 + dp[i + 1][0];
                    profit = max(sellkaro, skipkaro);
                }
                dp[i][buy] = profit;
            }
        }
        return dp[0][1];
    }
    int maxProfit(vector<int>& prices) {
        // int n = prices.size();
        // vector<vector<int>> dp(n, vector<int>(2, -1));
        // return solve(0, 1, prices, dp);
        return solveTab(prices);
    }
};