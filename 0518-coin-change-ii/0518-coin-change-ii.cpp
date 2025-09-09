class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        return solve(0, amount, coins, dp);
    }

    int solve(int i, int amt, vector<int>& coins, vector<vector<int>>& dp) {
        if (amt == 0) return 1;        // found valid way
        if (i >= coins.size()) return 0; // no coins left

        if (dp[i][amt] != -1) return dp[i][amt];

        int ways = 0;
        // option 1: skip this coin
        ways += solve(i + 1, amt, coins, dp);
        // option 2: take this coin
        if (amt >= coins[i]) {
            ways += solve(i, amt - coins[i], coins, dp);
        }

        return dp[i][amt] = ways;
    }
};
