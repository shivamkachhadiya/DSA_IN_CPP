class Solution {
public:
    bool solve(vector<vector<char>>& mat, int n, int m, string& word, int i,
               int j, int idx) {
        int size = word.size();

        if (idx >= size)
            return true;
        if (i < 0 || j < 0 || i >= n || j >= m)
            return false;

        if (mat[i][j] != word[idx])
            return false;
        char temp = mat[i][j];
        mat[i][j] = '$';

        bool result=solve(mat, n, m, word, i + 1, j, idx + 1)||
                    solve(mat, n, m, word, i, j + 1, idx + 1)||
                    solve(mat, n, m, word, i - 1, j, idx + 1)||
                    solve(mat, n, m, word, i, j - 1, idx + 1);

        mat[i][j] = temp;
        return result;
    }
    bool exist(vector<vector<char>>& mat, string word) {
        int n = mat.size();
        int m = mat[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(solve(mat,n,m,word,i,j,0))return true;
            }
        }
        return false;
    }
};