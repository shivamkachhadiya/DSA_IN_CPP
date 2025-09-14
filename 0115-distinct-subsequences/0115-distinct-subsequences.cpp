class Solution {
public:
    //  Pure Recursio
    int solve(string& s, string& t, int i, int j) {
        // base cases
        if (j < 0)
            return 1; // target string finished -> 1 way found
        if (i < 0)
            return 0; // source finished but target not -> no way

        if (s[i] == t[j]) {
            // either take this char or skip it
            return solve(s, t, i - 1, j - 1) + solve(s, t, i - 1, j);
        } else {
            // skip current char of s
            return solve(s, t, i - 1, j);
        }
    }

    //  Recursion + Memoizatio
    int solveDP(string& s, string& t, int i, int j, vector<vector<int>>& dp) {
        // base cases
        if (j < 0)
            return 1;
        if (i < 0)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (s[i] == t[j]) {
            return dp[i][j] = solveDP(s, t, i - 1, j - 1, dp) +
                              solveDP(s, t, i - 1, j, dp);
        } else {
            return dp[i][j] = solveDP(s, t, i - 1, j, dp);
        }
    }

    // \U0001f539 Leetcode functio
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solveDP(s, t, n - 1, m - 1, dp);
    }
};