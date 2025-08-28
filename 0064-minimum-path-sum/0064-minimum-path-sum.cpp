class Solution {
public:
    int f(int i, int j, vector<vector<int>>& dp, vector<vector<int>>& grid) {
        if (i == 0 && j == 0)
            return grid[0][0];
        if (i < 0 || j < 0)
            return INT_MAX;
        if (dp[i][j] != -1)
            return dp[i][j];
        int up = f(i - 1, j, dp, grid);
        int left = f(i, j - 1, dp, grid);

        // take min valid path and add current cell
        return dp[i][j] = grid[i][j] + min(up, left);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();    // number of rows
        int n = grid[0].size(); // number of columns
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return f(m - 1, n - 1, dp, grid);
    }
};