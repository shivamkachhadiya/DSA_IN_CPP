class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if(grid[0][0]==1)return -1;
        queue<pair<pair<int, int>, int>> q;
        q.push({{0, 0}, 0});
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        vis[0][0] = true;
        int delR[] = {0, 1, 0, 1, -1, -1, 1, -1};
        int delC[] = {-1, -1, 1, 1, 0, 1, 0, -1};
        while (!q.empty()) {
            int i = q.front().first.first;
            int j = q.front().first.second;
            int time = q.front().second;
            q.pop();
            if (i == n - 1 && j == m - 1)
                return time+1;
            for (int k = 0; k < 8; k++) {
                int delRow = i + delR[k];
                int delCol = j + delC[k];
                if (delRow >= 0 && delCol >= 0 && delRow < n && delCol < m) {
                    if (grid[delRow][delCol] != 1 &&
                        vis[delRow][delCol] == false) {
                        vis[delRow][delCol] = true;
                        q.push({{delRow, delCol}, time + 1});
                    }
                }
            }
        }

        return -1;
    }
};