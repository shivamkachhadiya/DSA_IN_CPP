class NumMatrix {
    vector<vector<int>> prefix;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = m ? matrix[0].size() : 0;
        prefix.assign(m+1, vector<int>(n+1, 0));
        
        // prefix sum build karo
        for(int i=1; i<=m; i++) {
            for(int j=1; j<=n; j++) {
                prefix[i][j] = matrix[i-1][j-1] 
                             + prefix[i-1][j] 
                             + prefix[i][j-1] 
                             - prefix[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        // inclusion-exclusion formula
        return prefix[row2+1][col2+1] 
             - prefix[row1][col2+1] 
             - prefix[row2+1][col1] 
             + prefix[row1][col1];
    }
};
