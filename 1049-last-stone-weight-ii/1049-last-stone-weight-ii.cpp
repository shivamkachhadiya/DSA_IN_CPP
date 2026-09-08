class Solution {
public:
    int helper(vector<int>& stones, int i, int target, vector<vector<int>>& dp) {
        if (i == stones.size() || target == 0) return 0;
        if (dp[i][target] != -1) return dp[i][target];

        // skip current stone
        int notTake = helper(stones, i+1, target, dp);

        // take current stone if possible
        int take = 0;
        if (stones[i] <= target) {
            take = stones[i] + helper(stones, i+1, target - stones[i], dp);
        }

        return dp[i][target] = max(take, notTake);
    }

    int lastStoneWeightII(vector<int>& stones) {
        int sum = 0;
        for (int x : stones) sum += x;
        int target = sum / 2;

        vector<vector<int>> dp(stones.size(), vector<int>(target+1, -1));
        int best = helper(stones, 0, target, dp);

        return sum - 2 * best;
    }
};
