class Solution {
public:
    int f(int i,int j,vector<vector<int>>&dp,vector<vector<int>>& obstacleGrid){
        // Out of bounds
        if(i<0 || j<0) return 0;

        // If blocked cell
        if(obstacleGrid[i][j] == 1) return 0;

        // If reached start cell and it's not blocked
        if(i==0 && j==0) return 1;

        // Memoization check
        if(dp[i][j] != -1) return dp[i][j];

        int up = f(i-1, j, dp, obstacleGrid);
        int left = f(i, j-1, dp, obstacleGrid);

        return dp[i][j] = up + left;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();        // number of rows
        int n = obstacleGrid[0].size();     // number of columns
        
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return f(m-1, n-1, dp, obstacleGrid);
    }
};
