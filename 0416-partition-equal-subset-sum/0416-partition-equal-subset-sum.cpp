class Solution {
public:
    bool solve(vector<int>& arr, int n, int i, int target, int sum,
                     vector<vector<int>>& dp) {
        if (target < sum) {
            return false;
        }
        if (target == sum) {
            return true;
        }
        if (i == n && target != sum) {
            return false;
        }

           if (dp[i][sum] != -1)
            return dp[i][sum];

        // include
        bool take = solve(arr, n, i + 1, target, sum + arr[i],dp);

        // exclude
        bool nottake = solve(arr, n, i + 1, target, sum,dp);

        return dp[i][sum]=take || nottake;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for (auto i : nums) {
            sum = sum + i;
        }


        if (sum % 2 == 0) {
            int target = sum / 2;
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
            return solve(nums, n, 0, target, 0,dp);
        } else {
            return 0;
        }
    }
};