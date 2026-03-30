class Solution {
public:
    int maxSum(vector<vector<int>>& arr) {

        int rows = arr.size();
        int cols = arr[0].size();

        int maxsum = INT_MIN;

        for (int i = 0; i < rows - 2; i++) {
            for (int j = 0; j < cols - 2; j++) {

                int currentSum = arr[i][j] + arr[i][j + 1] + arr[i][j + 2] +
                                 arr[i + 1][j + 1] + arr[i + 2][j] +
                                 arr[i + 2][j + 1] + arr[i + 2][j + 2];

                maxsum = max(maxsum, currentSum);
            }
        }

        return maxsum;
    }
};