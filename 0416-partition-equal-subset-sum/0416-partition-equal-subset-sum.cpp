class Solution {
public:
    bool solve(auto &arr, auto n, auto i, auto target, auto sum,
               auto &dp) {
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
        bool take = solve(arr, n, i + 1, target, sum + arr[i], dp);

        // exclude
        bool nottake = solve(arr, n, i + 1, target, sum, dp);

        return dp[i][sum] = take || nottake;
    }

    bool solveTab(vector<int>& arr, int n, int i, int target, int sum) {
        vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));

        for (int i = 0; i <= n; i++)
            dp[i][target] = true;

        // i=>0 to n-1
        // sum=>0 to target

        for (int i = n - 1; i >= 0; i--) {
            for (int sum = target; sum >= 0; sum--) {
                // include
                bool take = false;
                if (sum + arr[i] <= target)
                    take = dp[i + 1][sum + arr[i]];

                // exclude
                bool notake = dp[i + 1][sum];

                dp[i][sum] = take || notake;
            }
        }
        return dp[0][0];
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for (auto i : nums) {
            sum = sum + i;
        }

        if (sum % 2 == 0) {
            int target = sum / 2;
            // vector<vector<int>> dp(n, vector<int>(target + 1, -1));
            return solveTab(nums, n, 0, target, sum);
            // return solve(nums, n, 0, target, 0, dp);
        } else {
            return 0;
        }
    }
};