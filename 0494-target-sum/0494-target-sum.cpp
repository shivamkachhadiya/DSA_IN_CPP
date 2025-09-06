class Solution {
public:
    int f(vector<int>& nums, int target) {
    int total = accumulate(nums.begin(), nums.end(), 0);

    // If impossible, return 0
    if ((total + target) % 2 != 0 || abs(target) > total) return 0;

    int P = (total + target) / 2;

    vector<int> dp(P + 1, 0);
    dp[0] = 1;  // One way to make sum 0 (choose nothing)

    for (int num : nums) {
        // Traverse backward to avoid reusing elements
        for (int j = P; j >= num; j--) {
            dp[j] += dp[j - num];
        }
    }

    return dp[P];
}
    int findTargetSumWays(vector<int>& nums, int target) {
        return f(nums, target);
    }
};