class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        int directions[] = {0, 1, 0, -1, 0};
        int currentRow = 0;
        int currentCol = 0;
        int directionIndex = 0;
        for (int value = 1; value <= n * n; ++value) {
            matrix[currentRow][currentCol] = value;
            int nextRow = currentRow + directions[directionIndex];
            int nextCol = currentCol + directions[directionIndex + 1];
            if (nextRow < 0 || nextRow >= n || nextCol < 0 || nextCol >= n || matrix[nextRow][nextCol] != 0) {
                directionIndex = (directionIndex + 1) % 4;
            }
            currentRow += directions[directionIndex];
            currentCol += directions[directionIndex + 1];
        }
        return matrix;
    }
};