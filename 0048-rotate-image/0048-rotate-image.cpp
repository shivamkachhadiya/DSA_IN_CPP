class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        //bruite force time O(n^2) & space O(n^2)
        // vector<vector<int>> ansmatrix(n, vector<int>(n));
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         ansmatrix[j][n-1-i]=matrix[i][j];
        //     }
        // }
        // matrix=ansmatrix;

        //optimal time O(n^2) & space O(1)
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        for(int i=0;i<n;i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }        
    }
};