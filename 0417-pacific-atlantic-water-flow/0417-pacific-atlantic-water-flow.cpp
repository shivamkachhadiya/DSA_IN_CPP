class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<int>> pacific(m, vector<int>(n, 0));
        vector<vector<int>> atlantic(m, vector<int>(n, 0));
        vector<vector<int>> result;

        vector<pair<int,int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};

        // DFS function
        function<void(int,int,vector<vector<int>>&)> dfs = [&](int r, int c, vector<vector<int>>& visited) {
            visited[r][c] = 1;
            for (auto [dr, dc] : directions) {
                int nr = r + dr;
                int nc = c + dc;
                if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                if (visited[nr][nc]) continue;
                if (heights[nr][nc] < heights[r][c]) continue; // can only go to higher/equal
                dfs(nr, nc, visited);
            }
        };

        // Pacific border (top row + left col)
        for (int i = 0; i < m; i++) dfs(i, 0, pacific);
        for (int j = 0; j < n; j++) dfs(0, j, pacific);

        // Atlantic border (bottom row + right col)
        for (int i = 0; i < m; i++) dfs(i, n-1, atlantic);
        for (int j = 0; j < n; j++) dfs(m-1, j, atlantic);

        // Collect results
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    result.push_back({i, j});
                }
            }
        }

        return result;
    }
};
