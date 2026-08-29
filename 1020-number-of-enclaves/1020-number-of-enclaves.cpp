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
        // mark all boundary-connected lands
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if ((i == 0 || j == 0 || i == n - 1 || j == m - 1) &&
                    grid[i][j] == 1 && !vis[i][j]) {
                    dfs(grid, i, j, vis, n, m);
                }
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