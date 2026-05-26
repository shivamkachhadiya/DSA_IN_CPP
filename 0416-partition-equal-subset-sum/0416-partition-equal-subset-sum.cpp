class Solution {
public:
    bool solve(vector<int>& arr, int target, int sum, int n, int i,
               vector<vector<int>>& dp) {
        if (i >= n) {
            if (sum == target) {
                return true;
            } else {
                return false;
            }
        }
        if (sum > target)
            return false;
        if (sum == target)
            return true;

        if (dp[sum][i] != -1) {
            return dp[sum][i];
        }

        bool pick = solve(arr, target, sum + arr[i], n, i + 1, dp);
        bool nonpick = solve(arr, target, sum, n, i + 1, dp);

        return dp[sum][i] = pick || nonpick;
    }
    bool canPartition(vector<int>& nums) {
        int total = 0;
        for (auto i : nums) {
            total += i;
        }
        int n = nums.size();
        if (total % 2 == 0) {
            int target = total / 2;
            vector<vector<int>> dp(target + 1, vector<int>(n, -1));
            return solve(nums, target, 0, n, 0, dp);
        } else {
            return false;
        }
    }
};