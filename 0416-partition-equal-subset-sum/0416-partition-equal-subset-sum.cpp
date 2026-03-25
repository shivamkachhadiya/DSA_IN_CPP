class Solution {
public:
    // We use a 2D vector for memoization: dp[index][current_sum]
    // Using int instead of bool to store three states: -1 (unvisited), 0 (false), 1 (true)
    bool solve(vector<int>& nums, int n, int i, int sum, int tar, vector<vector<int>>& dp) {
        if (sum == tar)
            return true;
        if (i >= n || sum > tar)
            return false;
        
        // Fix 1: Check the 2D DP state
        if (dp[i][sum] != -1) {
            return dp[i][sum];
        }

        bool take = solve(nums, n, i + 1, sum + nums[i], tar, dp);
        bool notake = solve(nums, n, i + 1, sum, tar, dp);

        // Fix 2: Store the result in the 2D DP state
        return dp[i][sum] = (take || notake);
    }

    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        for (int i : nums) {
            totalSum += i;
        }

        if (totalSum % 2 != 0) return false;

        int n = nums.size();
        int tar = totalSum / 2;

        // Fix 3: Initialize a 2D DP table [index][sum]
        // Size: (number of elements) x (possible sum target + 1)
        vector<vector<int>> dp(n, vector<int>(tar + 1, -1));

        return solve(nums, n, 0, 0, tar, dp);
    }
};