class Solution {
public:
    int solve(vector<vector<int>>& mat, int n, int m, int i, int j,
              vector<vector<int>>& dp) {
        if (i == n - 1) {
            return mat[i][j];
        }
        if (dp[i][j] != -1)
            return dp[i][j];
        return dp[i][j] = mat[i][j] + min(solve(mat, n, m, i + 1, j, dp),
                                          solve(mat, n, m, i + 1, j + 1, dp));
    }
    int minimumTotal(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> dp(n, vector<int>());
        for (int i = 0; i < n; i++) {
            dp[i] = vector<int>(mat[i].size(), -1);
        }
        return solve(mat, n, m, 0, 0, dp);
    }
};