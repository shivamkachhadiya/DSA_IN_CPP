class Solution {
private:
    void dfs(int row, int col, vector<vector<int>>& vis,
             vector<vector<char>>& mat, int deltaRow[], int deltaCol[]) {
        // visit mark whichever you perfom dfs
        vis[row][col] = 1;
        int n = mat.size();
        int m = mat[0].size();

        // after visiting check top right down left
        for (int i = 0; i < 4; i++) {
            int newRow = row + deltaRow[i];
            int newCol = col + deltaCol[i];
            if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m &&
                !vis[newRow][newCol] && mat[newRow][newCol] == 'O') {
                dfs(newRow, newCol, vis, mat, deltaRow, deltaCol);
            }
        }
    }

public:
    void solve(vector<vector<char>>& mat) {
        int deltaRow[] = {-1, +0, +1, +0};
        int deltaCol[] = {+0, +1, +0, -1};

        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

        // boundry visit
        // traverse first row and last row
        for (int j = 0; j < m; j++) {
            if (!vis[0][j] && mat[0][j] == 'O') {
                dfs(0, j, vis, mat, deltaRow, deltaCol);
            }
            if (!vis[n - 1][j] && mat[n - 1][j] == 'O') {
                dfs(n - 1, j, vis, mat, deltaRow, deltaCol);
            }
        }

        // first column and last coloumn
        for (int i = 0; i < n; i++) {
            if (!vis[i][0] && mat[i][0] == 'O') {
                dfs(i, 0, vis, mat, deltaRow, deltaCol);
            }
            if (!vis[i][m - 1] && mat[i][m - 1] == 'O') {
                dfs(i, m - 1, vis, mat, deltaRow, deltaCol);
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && mat[i][j] == 'O')
                    // no touch make its 1
                    mat[i][j] = 'X';
            }
        }
    }
};