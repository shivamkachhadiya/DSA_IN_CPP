class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int rows = grid.size();
        int cols = grid[0].size();
        const int MOD = 1e9 + 7;
      
        // dp[i][j][remainder] = number of paths from (i,j) to (rows-1, cols-1) 
        // with path sum % k = remainder
        vector<vector<vector<int>>> dp(rows, vector<vector<int>>(cols, vector<int>(k, -1)));
      
        // Define recursive DFS function with memoization
        function<int(int, int, int)> dfs = [&](int row, int col, int currentSum) -> int {
            // Check if out of bounds
            if (row < 0 || row >= rows || col < 0 || col >= cols) {
                return 0;
            }
          
            // Update current sum with current cell value and take modulo k
            currentSum = (currentSum + grid[row][col]) % k;
          
            // Base case: reached bottom-right corner
            if (row == rows - 1 && col == cols - 1) {
                // Return 1 if sum is divisible by k, otherwise 0
                return currentSum == 0 ? 1 : 0;
            }
          
            // Check memoization cache
            if (dp[row][col][currentSum] != -1) {
                return dp[row][col][currentSum];
            }
          
            // Calculate number of valid paths by exploring both directions
            // Move down: (row + 1, col)
            // Move right: (row, col + 1)
            int pathCount = dfs(row + 1, col, currentSum) + dfs(row, col + 1, currentSum);
            pathCount %= MOD;
          
            // Store result in cache before returning
            dp[row][col][currentSum] = pathCount;
            return pathCount;
        };
      
        // Start DFS from top-left corner (0, 0) with initial sum 0
        return dfs(0, 0, 0);
    }
};