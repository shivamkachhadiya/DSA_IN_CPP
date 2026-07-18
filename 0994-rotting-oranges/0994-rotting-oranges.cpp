class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, pair<int, int>>> q;
        vector<vector<bool>> vis(n, vector<bool>(m, false));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    vis[i][j] = true;
                    q.push({0, {i, j}});
                }
            }
        }
        int ans = 0;
        while (!q.empty()) {
            int time = q.front().first;
            int i = q.front().second.first;
            int j = q.front().second.second;
            q.pop();

            ans = max(ans, time);

            int delI[] = {-1, +1, 0, 0};
            int delJ[] = {0, 0, +1, -1};

            for (int k = 0; k < 4; k++) {
                int newRow = i + delI[k];
                int newCol = j + delJ[k];

                if (newRow >= 0 && newCol >= 0 && newRow < n && newCol < m) {
                    if (grid[newRow][newCol] == 1 &&
                        vis[newRow][newCol] == false) {
                        vis[newRow][newCol] = true;
                        grid[newRow][newCol] = 2;
                        q.push({time + 1, {newRow, newCol}});
                    }
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