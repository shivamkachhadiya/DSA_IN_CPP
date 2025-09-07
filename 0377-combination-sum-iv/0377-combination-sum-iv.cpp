class Solution {
public:

    // ------------------- Recursive + Memoization -------------------
    int solveRecursion(vector<int>& nums, int target, vector<long long>& dp) {
        // Base cases
        if (target == 0) return 1;    // exact match, 1 way
        if (target < 0) return 0;     // overshoot, no way

        if (dp[target] != -1) return dp[target];  // already computed

        long long ans = 0;

        // Try every number in nums
        for (int i = 0; i < nums.size(); i++) {
            ans += solveRecursion(nums, target - nums[i], dp);
        }

        dp[target] = ans; // store result for current target
        return ans;
    }


    // ------------------- Main Function -------------------
    int combinationSum4(vector<int>& nums, int target) {
        // ----- Memoization approach -----
         vector<long long> dp(target + 1, -1);
         return (int)solveRecursion(nums, target, dp);

    }
};
