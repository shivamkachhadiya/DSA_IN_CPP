class Solution {
public:
    const int INF = 1e9;

    int solve(vector<int>& coins, int i, int target, vector<vector<int>>& dp) {

        // base case
        if (target == 0) return 0;

        if (i == 0) {
            if (target % coins[0] == 0)
                return target / coins[0];
            else
                return INF;
        }

        // memo check
        if (dp[i][target] != -1)
            return dp[i][target];

        // not take current coin
        int notake = solve(coins, i - 1, target, dp);

        // take current coin (unbounded)
        int take = INF;
        if (coins[i] <= target)
            take = 1 + solve(coins, i, target - coins[i], dp);

        return dp[i][target] = min(take, notake);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));

        int ans = solve(coins, n - 1, amount, dp);
        return (ans >= INF) ? -1 : ans;
    }
};
