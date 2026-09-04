class Solution {
public:
    bool solve(vector<int>& nums, int i, int sum, int target, vector<vector<int>>& dp) {
        if(sum == target) return true;
        if(i >= nums.size() || sum > target) return false;

        if(dp[i][sum] != -1) return dp[i][sum];

        bool take = solve(nums, i+1, sum+nums[i], target, dp);
        bool notake = solve(nums, i+1, sum, target, dp);

        return dp[i][sum] = take || notake;
    }

    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % 2 != 0) return false;

        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>((sum/2)+1, -1));

        return solve(nums, 0, 0, sum/2, dp);
    }
};
