class Solution {
public:
    int solveMem(int ind, int prev_ind, vector<int>& arr, int n,
                 vector<vector<int>>& dp) {

        // Base case
        if (ind == n)
            return 0;

        // Memoization check
        if (dp[ind][prev_ind + 1] != -1)
            return dp[ind][prev_ind + 1];

        // Not take
        int len = solveMem(ind + 1, prev_ind, arr, n, dp);

        // Take
        if (prev_ind == -1 || arr[ind] > arr[prev_ind]) {
            len = max(len, 1 + solveMem(ind + 1, ind, arr, n, dp));
        }

        return dp[ind][prev_ind + 1] = len;
    }

    int lengthOfLIS(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return solveMem(0, -1, arr, n, dp);
    }
};
