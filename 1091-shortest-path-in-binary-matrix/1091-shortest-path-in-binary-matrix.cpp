class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid[0][0] == 1)
            return -1;

        int n = grid.size();
        int m = grid[0].size();
        if (grid[n - 1][m - 1] == 1)
            return -1;
        queue<pair<pair<int, int>, int>> q;
        q.push({{0, 0}, 0});

        int delR[] = {0, 1, 0, -1, -1, 1, 1, -1};
        int delC[] = {-1, 1, 1, 1, 0, -1, 0, -1};
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        int ans = -1;
        vis[0][0] = true;
        while (!q.empty()) {
            int i = q.front().first.first;
            int j = q.front().first.second;
            int time = q.front().second;
            if (i == n - 1 && j == m - 1)
                return time + 1;

            q.pop();
            for (int k = 0; k < 8; k++) {
                int newRow = i + delR[k];
                int newCol = j + delC[k];

                if (newRow >= 0 && newCol >= 0 && newRow < n && newCol < m &&
                    vis[newRow][newCol] == false && grid[newRow][newCol] == 0) {
                    vis[newRow][newCol] = true;
                    q.push({{newRow, newCol}, time + 1});
                }
            }
        }
        return -1;
    }
};