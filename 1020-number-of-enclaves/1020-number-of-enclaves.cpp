class Solution {
public:
    int delRow[4] = {-1, 1, 0, 0};
    int delCol[4] = {0, 0, -1, 1};
    void dfs(vector<vector<int>>& grid, int i, int j, vector<vector<bool>>& vis,
             int n, int m) {
        vis[i][j] = true;
        for (int k = 0; k < 4; k++) {
            int newRow = i + delRow[k];
            int newCol = j + delCol[k];
            if (newRow < n && newCol < m && newRow >= 0 && newCol >= 0 &&
                vis[newRow][newCol] == false && grid[newRow][newCol] == 1) {
                dfs(grid, newRow, newCol, vis, n, m);
            }
        }
    }

    int dfs_final(vector<vector<int>>& grid, int i, int j,
                  vector<vector<bool>>& vis, int n, int m) {
        vis[i][j] = true;
        int count = 1;
        for (int k = 0; k < 4; k++) {
            int newRow = i + delRow[k];
            int newCol = j + delCol[k];
            if (newRow < n && newCol < m && newRow >= 0 && newCol >= 0 &&
                vis[newRow][newCol] == false && grid[newRow][newCol] == 1) {
                count += dfs_final(grid, newRow, newCol, vis, n, m);
            }
        }
        return count;
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));

        // top boundary
        for (int col = 0; col < m; col++) {
            if (!vis[0][col] && grid[0][col] == 1) {
                dfs(grid, 0, col, vis, n, m);
            }
        }

        // bottom boundary
        for (int col = 0; col < m; col++) {
            if (!vis[n - 1][col] && grid[n - 1][col] == 1) {
                dfs(grid, n - 1, col, vis, n, m);
            }
        }

        // left boundary
        for (int row = 0; row < n; row++) {
            if (!vis[row][0] && grid[row][0] == 1) {
                dfs(grid, row, 0, vis, n, m);
            }
        }

        // right boundary
        for (int row = 0; row < n; row++) {
            if (!vis[row][m - 1] && grid[row][m - 1] == 1) {
                dfs(grid, row, m - 1, vis, n, m);
            }
        }

        int count = 0;
        for (int i = 1; i < n - 1; i++) {
            for (int j = 1; j < m - 1; j++) {
                if (vis[i][j] == false && grid[i][j] == 1) {
                    count += dfs_final(grid, i, j, vis, n, m);
                }
            }
        }
        return count;
    }
};