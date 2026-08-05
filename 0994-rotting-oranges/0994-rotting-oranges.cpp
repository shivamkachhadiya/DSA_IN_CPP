class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<pair<int, int>, int>> q;
        int fresh = 0;
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1)
                    fresh++;
                if (grid[i][j] == 2) {
                    vis[i][j] = true;
                    // grid[i][j] = 0;

                    q.push({{i, j}, 0});
                }
            }
        }
        int delRow[] = {1, 0, -1, 0};
        int delCol[] = {0, 1, 0, -1};
        int ans = -1;
        if (fresh > 0 && q.empty())
            return -1;
        if (fresh == 0)
            return 0;
        while (!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int time = q.front().second;
            ans = max(ans, time);

            q.pop();
            for (int k = 0; k < 4; k++) {
                int newRow = delRow[k] + row;
                int newCol = delCol[k] + col;
                if (newRow >= 0 && newCol >= 0 && newRow < n && newCol < m &&
                    vis[newRow][newCol] == false && grid[newRow][newCol] == 1) {
                    vis[newRow][newCol] = true;
                    grid[newRow][newCol] = 2;
                    q.push({{newRow, newCol}, time + 1});
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1)
                    return -1;
            }
        }
        return ans;
    }
};