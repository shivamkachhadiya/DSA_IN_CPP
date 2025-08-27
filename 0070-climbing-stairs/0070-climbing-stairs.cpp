class Solution {
public:
    int solve(int n, int i, vector<int> &dp) {
        if (i == n) return 1;   // reached the top
        if (i > n) return 0;    // overshoot
        if (dp[i] != -1) return dp[i];  // already computed

        dp[i] = solve(n, i + 1, dp) + solve(n, i + 2, dp);
        return dp[i];
    }

    int climbStairs(int n) {
        vector<int> dp(n + 1, -1);
        return solve(n, 0, dp);
    }
};