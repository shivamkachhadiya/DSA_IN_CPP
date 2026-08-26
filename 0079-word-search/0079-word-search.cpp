class Solution {
public:
    int delRow[4] = {-1, 1, 0, 0};
    int delCol[4] = {0, 0, -1, 1};
    bool solve(vector<vector<char>>& mat, string& word, int i, int j, int n,
               int m, int idx) {
        if (idx == word.size())
            return true;
        if (i < 0 || j < 0 || i >= n || j >= m || mat[i][j] == '#')
            return false;
        if (mat[i][j] != word[idx])
            return false;
        char temp = mat[i][j];
        mat[i][j] = '#';
        for (int k = 0; k < 4; k++) {
            int new_row = i + delRow[k];
            int new_col = j + delCol[k];
            if (solve(mat, word, new_row, new_col, n, m, idx + 1)) {
                return true;
            }
        }
        mat[i][j] = temp;
        return false;
    }
    bool exist(vector<vector<char>>& mat, string word) {
        int n = mat.size();
        int m = mat[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == word[0] && solve(mat, word, i, j, n, m, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
};