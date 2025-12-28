class Solution {
public:
    bool solve(vector<int>& arr, int n, int index, int target, int sum) {
        if (sum == target)
            return true;
        if (index == n)
            return false;
        if (sum > target)
            return false;

        // take
        sum = sum + arr[index];
        bool take = solve(arr, n, index + 1, target, sum);

        // backtrack
        sum = sum - arr[index];

        // notake
        bool nottake = solve(arr, n, index + 1, target, sum);

        return take || nottake;
    }

    bool solveMem(vector<int>& arr, int n, int index, int target, int sum,
                  vector<vector<int>>& dp) {
        if (sum == target)
            return true;
        if (index == n)
            return false;
        if (sum > target)
            return false;
        if (dp[index][sum] != -1)
            return dp[index][sum];
        // take
        sum = sum + arr[index];
        bool take = solveMem(arr, n, index + 1, target, sum, dp);

        // backtrack
        sum = sum - arr[index];

        // notake
        bool nottake = solveMem(arr, n, index + 1, target, sum, dp);

        return dp[index][sum] = take || nottake;
    }

    bool solveTab(vector<int>& arr, int n, int index, int target, int sum,
                  vector<vector<bool>>& dp) {
        for (int i = 0; i <= n; i++)
            dp[i][0] = true;
         for (int i = 1; i <= n; i++) {
        for (int s = 1; s <= target; s++) {
            bool nottake = dp[i-1][s];
            bool take = false;
            if (s >= arr[i-1]) take = dp[i-1][s - arr[i-1]];
            dp[i][s] = take || nottake;
        }
    }

    return dp[n][target];
    }

    bool canPartition(vector<int>& arr) {
        int n = arr.size();
        int target = 0;
        for (auto x : arr) {
            target = target + x;
        }

        if (target % 2 == 0) {
            target = target / 2;
            //vector<vector<int>> dp(n, vector<int>(target + 1, -1));

            // return solve(arr, n, 0, target, 0);
            // return solveMem(arr, n, 0, target, 0, dp);
            vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));

            return solveTab(arr, n, 0, target, 0, dp);
        } else {
            return false;
        }
    }
};