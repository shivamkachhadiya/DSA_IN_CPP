class Solution {
public:
    bool solve(vector<int>& nums, int n, int i, int sum, int tar,
               vector<vector<int>>& dp) {
        if (sum == tar)
            return true;
        if (i >= n || sum > tar)
            return false;
        if (dp[i][sum] != -1) {
            return dp[i][sum];
        }

        bool take = solve(nums, n, i + 1, sum + nums[i], tar, dp);

        bool notake = solve(nums, n, i + 1, sum, tar, dp);
        return dp[i][sum] = take || notake;
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int i : nums) {
            sum += i;
        }
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(sum/2 + 1, -1));
        if (sum % 2 == 0) {
            return solve(nums, nums.size(), 0, 0, sum / 2, dp);
        } else {
            return false;
        }
    }
};