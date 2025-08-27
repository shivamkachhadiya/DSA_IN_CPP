class Solution {
public:
    int solve(vector<int>& nums, int n, vector<int>& temp) {
        // int n=nums.size();
        if (n == 0)
            return 0;
        if (n == 1)
            return nums[0];
        vector<int> dp(n, -1);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < n; i++) {
            int pick = nums[i] + dp[i - 2];
            int non_pick = 0 + dp[i - 1];
            dp[i] = max(pick, non_pick);
        }
        return dp[n - 1];
    }
    int rob(vector<int>& nums) {
        
        vector<int> temp1;
        vector<int> temp2;
        int n = nums.size();
        if (n == 0)
            return 0;
        if (n == 1)
            return nums[0];
        for (int i = 0; i < n - 1; i++) {
            temp1.push_back(nums[i]);
        }
        for (int i = 1; i < n; i++) {
            temp2.push_back(nums[i]);
        }

        int ans1 = solve(temp1, temp1.size(), temp1);
        int ans2 = solve(temp2, temp2.size(), temp2);

        return max(ans1, ans2);
    }
};