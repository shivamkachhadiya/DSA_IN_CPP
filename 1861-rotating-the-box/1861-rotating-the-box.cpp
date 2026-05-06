class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int rows = box.size();
        int cols = box[0].size();
        vector<vector<char>> result(cols, vector<char>(rows, '.'));

        for (int i = 0; i < rows; i++) {
            int empty_spot = cols - 1;
            for (int j = cols - 1; j >= 0; j--) {
                if (box[i][j] == '#') {
                    box[i][j] = '.';
                    box[i][empty_spot--] = '#';
                } else if (box[i][j] == '*') {
                    empty_spot = j - 1;
                }
            }
            for (int j = 0; j < cols; j++) {
                result[j][rows - 1 - i] = box[i][j];
            }
        }

        return result;
    }
};