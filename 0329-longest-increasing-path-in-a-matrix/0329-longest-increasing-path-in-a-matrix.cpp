// class Solution {
// public:
//     int longestIncreasingPath(vector<vector<int>>& matrix) {
//         if (matrix.empty() || matrix[0].empty())
//             return 0;

//         int m = matrix.size();
//         int n = matrix[0].size();
//         int longestPath = 0;

//         for (int i = 0; i < m; i++) {
//             for (int j = 0; j < n; j++) {
//                 int path = dfs(matrix, m, n, i, j);
//                 longestPath = max(longestPath, path);
//             }
//         }
//         return longestPath;
//     }

// private:
//     // Call each direction separately (up, down, left, right)
//     int dfs(vector<vector<int>>& mat, int m, int n, int i, int j) {
//         int maxPath = 0;

//         // down: (i+1, j)
//         if (i + 1 < m && mat[i + 1][j] > mat[i][j]) {
//             maxPath = max(maxPath, dfs(mat, m, n, i + 1, j));
//         }

//         // up: (i-1, j)
//         if (i - 1 >= 0 && mat[i - 1][j] > mat[i][j]) {
//             maxPath = max(maxPath, dfs(mat, m, n, i - 1, j));
//         }

//         // right: (i, j+1)
//         if (j + 1 < n && mat[i][j + 1] > mat[i][j]) {
//             maxPath = max(maxPath, dfs(mat, m, n, i, j + 1));
//         }

//         // left: (i, j-1)
//         if (j - 1 >= 0 && mat[i][j - 1] > mat[i][j]) {
//             maxPath = max(maxPath, dfs(mat, m, n, i, j - 1));
//         }

//         return maxPath + 1; // 1 for current cell
//     }
// };



class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;

        m = matrix.size();
        n = matrix[0].size();
        dp.assign(m, vector<int>(n, 0));

        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans = max(ans, dfs(matrix, i, j));
            }
        }
        return ans;
    }

private:
    int m, n;
    vector<vector<int>> dp;

    int dfs(vector<vector<int>>& matrix, int i, int j) {
        if (dp[i][j] != 0) return dp[i][j];

        int best = 1; // at least the current cell

        if (i + 1 < m && matrix[i + 1][j] > matrix[i][j]) {
            best = max(best, 1 + dfs(matrix, i + 1, j));
        }
        if (i - 1 >= 0 && matrix[i - 1][j] > matrix[i][j]) {
            best = max(best, 1 + dfs(matrix, i - 1, j));
        }
        if (j + 1 < n && matrix[i][j + 1] > matrix[i][j]) {
            best = max(best, 1 + dfs(matrix, i, j + 1));
        }
        if (j - 1 >= 0 && matrix[i][j - 1] > matrix[i][j]) {
            best = max(best, 1 + dfs(matrix, i, j - 1));
        }

        return dp[i][j] = best;
    }
};