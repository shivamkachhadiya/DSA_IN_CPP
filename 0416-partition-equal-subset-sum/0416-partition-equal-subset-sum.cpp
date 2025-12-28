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
        // base case
        // base case: sum 0 always possible
        for (int i = 0; i <= n; i++)
            dp[i][0] = true;

        // fill table in recursion-like order
        for (int index = n - 1; index >= 0;
             index--) {                         // recursion index 0 → n-1
            for (int t = 0; t <= target; t++) { // recursion sum 0 → target
                bool incl = false;
                if (t - arr[index] >= 0)
                    incl =
                        dp[index + 1][t - arr[index]]; // take current element

                bool excl = dp[index + 1][t]; // do not take current element

                dp[index][t] = incl || excl;
            }
        }

        // answer starts from index 0, sum 0
        return dp[0][target];
                  }

        bool canPartition(vector<int> & arr) {
            int n = arr.size();
            int target = 0;
            for (auto x : arr) {
                target = target + x;
            }

            if (target % 2 == 0) {
                target = target / 2;
                // vector<vector<int>> dp(n, vector<int>(target + 1, -1));

                // return solve(arr, n, 0, target, 0);
                // return solveMem(arr, n, 0, target, 0, dp);
                vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));

                return solveTab(arr, n, 0, target, 0, dp);
            } else {
                return false;
            }
        }
    };