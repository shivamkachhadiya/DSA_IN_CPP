class Solution {
public:
    // Recursive function with memoization
    bool f(int index, int target, vector<int>& arr, vector<vector<int>>& dp) {
        // Base case: target found
        if (target == 0) {
            return true;
        }

        // Base case: only 1 element left to check
        if (index == 0) {
            return arr[0] == target;
        }

        // If already computed, return stored value
        if (dp[index][target] != -1) {
            return dp[index][target];
        }

        // Choice 1: do not take current element
        bool notTake = f(index - 1, target, arr, dp);

        // Choice 2: take current element (if possible)
        bool take = false;
        if (arr[index] <= target) {
            take = f(index - 1, target - arr[index], arr, dp);
        }

        // Store result in dp and return
        dp[index][target] = take || notTake;
        return dp[index][target];
    }

    // Main function: check if array can be partitioned into equal sum subsets
    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        // Step 1: calculate total sum
        int totalSum = 0;
        for (int num : nums) {
            totalSum += num;
        }

        // Step 2: if sum is odd, partition not possible
        if (totalSum % 2 != 0) {
            return false;
        }

        // Step 3: target = half of total sum
        int target = totalSum / 2;

        // Step 4: initialize dp table (n x (target+1)) with -1
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));

        // Step 5: call recursive function
        return f(n - 1, target, nums, dp);
    }
};