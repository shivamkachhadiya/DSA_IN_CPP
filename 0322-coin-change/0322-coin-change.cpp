class Solution {
public:
    int minCoins(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0; // base case: 0 amount = 0 coins

        for (int i = 1; i <= amount; i++) {
            for (int c : coins) {
                if (i - c >= 0 && dp[i - c] != INT_MAX) {
                    dp[i] = min(dp[i], 1 + dp[i - c]);
                }
            }
        }

        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
    int coinChange(vector<int>& coins, int amount) {
        int ans = minCoins(coins, amount);
        if (ans == -1)
            return -1;
        else
            return ans;

        return 0;
    }
};