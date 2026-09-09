class Solution {
public:
    int solve(vector<int>& arr, int n, int i, int p, vector<vector<int>>& dp) {
        if (i >= arr.size())
            return 0;
        if (dp[i][p+1] != -1)
            return dp[i][p+1];
        int take = 0;
        if (p == -1 || arr[p] < arr[i]) {
            take += 1 + solve(arr, n, i + 1, i, dp);
        }
        int notake = solve(arr, n, i + 1, p, dp);
        return dp[i][p+1] = max(take, notake);
    }
    int lengthOfLIS(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return solve(arr, n, 0, -1, dp);
    }
};