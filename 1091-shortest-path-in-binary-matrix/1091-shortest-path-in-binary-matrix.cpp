class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if (grid[0][0] == 1)
            return -1;
        if(n==1)return 1;
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        queue<pair<pair<int, int>, int>> q;
        q.push({{0, 0}, 1});
        vis[0][0] = true;
        int delRow[] = {1, 1, 0, -1, -1, -1, 0, 1};
        int delCol[] = {0, -1, 1, -1, 0, 1, -1, 1};
        while (!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int time = q.front().second;
            q.pop();
            for (int k = 0; k < 8; k++) {
                int newRow = delRow[k] + row;
                int newCol = delCol[k] + col;
                if (newRow < n && newCol < m && newRow >= 0 && newCol >= 0 &&
                    vis[newRow][newCol] == false && grid[newRow][newCol] == 0) {
                    vis[newRow][newCol] = true;
                    q.push({{newRow, newCol}, time + 1});
                    if (newRow == n - 1 && newCol == m - 1)
                        return time + 1;
                }
            }
        }
        return -1;
    }
};