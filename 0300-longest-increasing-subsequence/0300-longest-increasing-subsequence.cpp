class Solution {
public:
    int solve(int i, int prev, vector<int>& arr, int n,
              vector<vector<int>>& dp) {
        if (i == n) {
            return 0;
        }
        if (dp[i][prev + 1] != -1) {
            return dp[i][prev + 1];
        }
        // take
        int take = 0;

        if (prev == -1 || arr[i] > arr[prev]) {
            take = 1 + solve(i + 1, i, arr, n, dp);
        }
        // notake
        int notake = solve(i + 1, prev, arr, n, dp);
        return dp[i][prev + 1] = max(take, notake);
    }
    int lengthOfLIS(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return solve(0, -1, arr, n, dp);
    }
};