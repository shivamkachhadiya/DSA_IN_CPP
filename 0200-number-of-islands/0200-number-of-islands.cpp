class Solution {
public:
    queue<pair<int, int>> q;

    void bfs(vector<vector<char>>& grid, int n, int m,vector<vector<bool>>& vis, int i, int j) {
        int delR[] = {-1, 1, 0, 0};
        int delC[] = {0, 0, -1, 1};

      
            while (!q.empty()) {
                int row = q.front().first;
                int col = q.front().second;
                q.pop();
                for (int k = 0; k < 4; k++) {
                    int newRow = row + delR[k];
                    int newCol = col + delC[k];
                    if (newRow >= 0 && newCol >= 0 && newRow < n &&
                        newCol < m && grid[newRow][newCol] == '1' &&
                        vis[newRow][newCol] == false) {
                        vis[newRow][newCol] = true;
                        q.push({newRow, newCol});
                    }
                }
            }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        int isLands = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (vis[i][j] == false && grid[i][j] == '1') {
                    q.push({i, j});
                    vis[i][j] = true;
                    bfs(grid, n, m, vis, i, j);
                    isLands++;
                }
            }
        }
        return isLands;
    }
};