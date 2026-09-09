class Solution {
public:
    int solve(vector<int>& nums, int n, int i, int p, vector<vector<int>>& dp) {
        if(i >= n) return 0;
        if(dp[i][p+1] != -1) return dp[i][p+1];

        int take = 0;
        if(p == -1 || nums[i] % nums[p] == 0) {
            take = 1 + solve(nums, n, i+1, i, dp);
        }
        int notake = solve(nums, n, i+1, p, dp);

        return dp[i][p+1] = max(take, notake);
    }

    // helper to reconstruct subset using recursion
    void build(vector<int>& nums, int n, int i, int p, int len,
               vector<vector<int>>& dp, vector<int>& subset) {
        if(i >= n || len == 0) return;

        // if taking nums[i] gives correct length
        if((p == -1 || nums[i] % nums[p] == 0) &&
           1 + solve(nums, n, i+1, i, dp) == len) {
            subset.push_back(nums[i]);
            build(nums, n, i+1, i, len-1, dp, subset);
        } else {
            build(nums, n, i+1, p, len, dp, subset);
        }
    }

    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // important

        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n+1, -1));

        int maxLen = solve(nums, n, 0, -1, dp);

        vector<int> subset;
        build(nums, n, 0, -1, maxLen, dp, subset);
        return subset;
    }
};
