class Solution {
public:
    int delRow[4] = {-1, 1, 0, 0};   // 4 directions: up, down, left, right
    int delCol[4] = {0, 0, -1, 1};

    // DFS to mark all connected land cells
    void dfs(vector<vector<int>>& grid, int n, int m, int i, int j,
             vector<vector<bool>>& vis) {
        vis[i][j] = true;
        for(int k=0;k<4;k++){
            int newRow = i + delRow[k];
            int newCol = j + delCol[k];
            if(newRow >= 0 && newCol >= 0 && newRow < n && newCol < m &&
               !vis[newRow][newCol] && grid[newRow][newCol] == 0) {
                dfs(grid, n, m, newRow, newCol, vis);
            }
        }
    }

    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));

        // Step 1: Mark boundary-connected islands (not closed)
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((i==0 || j==0 || i==n-1 || j==m-1) && grid[i][j]==0 && !vis[i][j]){
                    dfs(grid, n, m, i, j, vis);
                }
            }
        }

        // Step 2: Count closed islands
        int count = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 0 && !vis[i][j]) {
                    dfs(grid, n, m, i, j, vis);
                    count++;
                }
            }
        }
        return count;
    }
};
