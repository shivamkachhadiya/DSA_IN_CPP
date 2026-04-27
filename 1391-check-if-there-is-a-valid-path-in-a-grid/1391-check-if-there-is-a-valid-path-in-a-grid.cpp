class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dirs = {
            {},                 // 0 unused
            {0, -1, 0, 1},      // 1: left-right
            {-1, 0, 1, 0},      // 2: up-down
            {0, -1, 1, 0},      // 3: left-down
            {0, 1, 1, 0},       // 4: right-down
            {0, -1, -1, 0},     // 5: left-up
            {0, 1, -1, 0}       // 6: right-up
        };
        
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        queue<pair<int,int>> q;
        q.push({0,0});
        vis[0][0] = true;
        
        // BFS traversal
        while (!q.empty()) {
            auto [x,y] = q.front(); q.pop();
            if (x == m-1 && y == n-1) return true;
            
            int type = grid[x][y];
            for (int k = 0; k < 2; k++) {
                int dx = dirs[type][2*k], dy = dirs[type][2*k+1];
                int nx = x + dx, ny = y + dy;
                
                // bounds check
                if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
                
                if (vis[nx][ny]) continue;
                
                // check if neighbor connects back
                int ntype = grid[nx][ny];
                for (int kk = 0; kk < 2; kk++) {
                    int ndx = dirs[ntype][2*kk], ndy = dirs[ntype][2*kk+1];
                    if (nx + ndx == x && ny + ndy == y) {
                        vis[nx][ny] = true;
                        q.push({nx,ny});
                    }
                }
            }
        }
        return false;
    }
};
