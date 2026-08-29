class Solution {
public:
    int delRow[4] = {-1, 1, 0, 0};
    int delCol[4] = {0, 0, -1, 1};
    int dfs(vector<vector<int>>& grid, int n, int m, vector<vector<bool>>& vis,
             int i, int j) {
        vis[i][j] = true;
        int num_of_inside=1;
        for (int k = 0; k < 4; k++) {
            int newRow = i + delRow[k];
            int newCol = j + delCol[k];

            if (newRow < n && newCol < m && newRow >= 0 && newCol >= 0 &&
                vis[newRow][newCol] == false && grid[newRow][newCol] == 1) {
                num_of_inside+=dfs(grid, n, m, vis, newRow, newCol);
            }
        }
        return num_of_inside;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (vis[i][j] == false && grid[i][j] == 1) {
                   
                    count=max(count, dfs(grid, n, m, vis, i, j));
                }
            }
        }
        return count;
    }
};