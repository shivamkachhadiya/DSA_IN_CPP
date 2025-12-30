class Solution {
public:
    static const int MOD = 1e9 + 7;

    // ---------- Recursive version (with modulo) ----------
    int solve(int diceLeft, int faces, int target) {
        if (target < 0) return 0;
        if (diceLeft == 0) return (target == 0);

        int ways = 0;
        for (int face = 1; face <= faces; face++) {
            ways = (ways + solve(diceLeft - 1, faces, target - face)) % MOD;
        }
        return ways;
    }

    // ---------- Tabulation version ----------
    int tab(int n, int k, int target, vector<vector<int>>& dp) {
        dp[0][0] = 1;

        for (int dice = 1; dice <= n; dice++) {
            for (int sum = 1; sum <= target; sum++) {
                for (int face = 1; face <= k; face++) {
                    if (sum - face >= 0) {
                        dp[dice][sum] =
                            (dp[dice][sum] + dp[dice - 1][sum - face]) % MOD;
                    }
                }
            }
        }
        return dp[n][target];
    }

    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
        return tab(n, k, target, dp);
        // return solve(n, k, target); // also works but slow
    }
};
