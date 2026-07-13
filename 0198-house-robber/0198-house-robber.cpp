class Solution {
public:
    int solveRec(vector<int>& arr, int n, int i, vector<int>& dp) {
        if (i >= n)
            return 0;
        if (dp[i] != -1)
            return dp[i];
        int pick = arr[i] + solveRec(arr, n, i + 2, dp);
        int notpick = 0 + solveRec(arr, n, i + 1, dp);
        return dp[i] = max(pick, notpick);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n);
           if (n == 1)
            return nums[0];

        // return solveRec(nums,nums.size(),0,dp);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < n; i++) {
            int pick = nums[i] + dp[i - 2];
            int notpick = 0 + dp[i - 1];
            dp[i] = max(pick, notpick);
        }

        return dp[n-1];
    }
};