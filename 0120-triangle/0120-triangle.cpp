class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();

        // Create a 2D dp table of size n x n, initialized to 0
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // Base case: last row of dp = last row of triangle
        for (int j = 0; j < n; j++) {
            dp[n - 1][j] = triangle[n - 1][j];
        }

        // Bottom-up: fill dp from second last row up to the top
        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j <= i; j++) {
                // Option 1: go down
                int down = triangle[i][j] + dp[i + 1][j];
                // Option 2: go diagonal
                int diagonal = triangle[i][j] + dp[i + 1][j + 1];
                // Take minimum
                dp[i][j] = min(down, diagonal);
            }
        }

        // Answer will be stored at the top of dp
        return dp[0][0];
    }
};
