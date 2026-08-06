class Solution {
public:
    int solve(int n, int i, vector<int>& dp) {
        if (i == n) return 1;       // reached exactly top → valid way
        if (i > n) return 0;        // overshoot → invalid
        if (dp[i] != -1) return dp[i];

        int one_way = solve(n, i + 1, dp);
        int two_way = solve(n, i + 2, dp);

        return dp[i] = one_way + two_way;
    }

    int climbStairs(int n) {
        vector<int> dp(n + 1, -1);
        return solve(n, 0, dp);
    }
};
