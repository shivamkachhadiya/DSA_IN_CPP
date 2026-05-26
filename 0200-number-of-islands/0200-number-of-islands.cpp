class Solution {
   public:
    void dfs(vector<vector<char>>& grid, int m, int n, int i, int j, vector<vector<bool>>& vis) {
        if (i < 0 || j < 0 || i >= m || j >= n || vis[i][j] || grid[i][j] == '0') {
            return;
        }
        vis[i][j] = true;
        dfs(grid, m, n, i - 1, j, vis);
        dfs(grid, m, n, i, j + 1, vis);
        dfs(grid, m, n, i + 1, j, vis);
        dfs(grid, m, n, i, j - 1, vis);
    }
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;

        int island = 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1' && !vis[i][j]) {
                    dfs(grid, m, n, i, j, vis);
                    island++;
                }
            }
        }
        return island;
    }
};
