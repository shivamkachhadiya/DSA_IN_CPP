class Solution {
public:
    int ans = 0;
    int solve(vector<vector<int>>& grid, int i, int j,vector<vector<int>>& dp) {
        if (i < 0 || j < 0)
            return 1e9;
        if (i == 0 && j == 0) {
            return grid[0][0];
        }

           if (dp[i][j] != -1)
            return dp[i][j];

        int top = grid[i][j]+solve(grid, i - 1, j,dp);
        int left = grid[i][j]+solve(grid, i, j - 1,dp);
        return dp[i][j]=min(top,left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
                vector<vector<int>> dp(m + 1, vector<int>(n, -1));

        return solve(grid,m - 1, n - 1, dp);
    }
};