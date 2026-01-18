class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        //{{2,0},1}
        queue<pair<pair<int, int>, int>> q;

        // visited vector
        vector<vector<int>> vis(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    vis[i][j] = 2;
                }
            }
        }
        int t = 0;
        int delrow[] = {-1, 0, +1, 0};
        int delcol[] = {0, 1, 0, -1};
        while (!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int time = q.front().second;
            q.pop();
            t = max(time, t);
            for (int i = 0; i < 4; i++) {
                int N_row = delrow[i] + row;
                int N_col = delcol[i] + col;
                if (N_row >= 0 && N_col >= 0 && N_row < n && N_col < m &&
                    vis[N_row][N_col] != 2 && grid[N_row][N_col] == 1) {
                    q.push({{N_row, N_col}, time + 1});
                    vis[N_row][N_col] = 2;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (vis[i][j] != 2 && grid[i][j] == 1) {
                    return -1;
                }
            }
        }
        return t;
    }
};