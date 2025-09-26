class Solution {
  public:
    int solve(int i, int j, vector<int>& arr) {
        if(i>j)return 0;
        if (i == j) return arr[i];
        if (j == i + 1) return max(arr[i], arr[j]);

        // if I pick left coin (arr[i])
        int pickLeft = arr[i] + min(solve(i+2, j, arr), solve(i+1, j-1, arr));

        // if I pick right coin (arr[j])
        int pickRight = arr[j] + min(solve(i+1, j-1, arr), solve(i, j-2, arr));

        return max(pickLeft, pickRight);
    }
    int solveMEM(int i, int j, vector<int>& arr, vector<vector<int>>& dp) {
        if (i > j) return 0;
        if (i == j) return arr[i];
        if (j == i+1) return max(arr[i], arr[j]);

        if (dp[i][j] != -1) return dp[i][j];

        // both recursive calls should also use solveMEM
        int takeLeft  = arr[i] + min(solveMEM(i+2, j, arr, dp), solveMEM(i+1, j-1, arr, dp));
        int takeRight = arr[j] + min(solveMEM(i+1, j-1, arr, dp), solveMEM(i, j-2, arr, dp));

        return dp[i][j] = max(takeLeft, takeRight);
    }

    int maximumAmount(vector<int> &arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solveMEM(0, n-1, arr, dp);
    }
};