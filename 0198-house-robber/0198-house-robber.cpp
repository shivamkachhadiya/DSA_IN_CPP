class Solution {
public:
    int solve(int index, vector<int>& nums, vector<int>& dp) {

        if (index == 0)
            return nums[index];
        if (index < 0)
            return 0;
        if(dp[index]!=-1){
            return dp[index];
        }

        int pick = nums[index] + solve(index - 2, nums,dp);

        int not_pick = 0 + solve(index - 1, nums,dp);

        dp[index]= max(pick, not_pick);

        return dp[index];
    }
    int rob(vector<int>& nums) {

        // recursion + memoization

        // int n = nums.size();
        // vector<int>dp(n,-1);
        // return solve(n - 1, nums,dp);

        //--------------------recursion + memoization + tabulation-----------------------

        int n = nums.size();
        if (n == 0)
            return 0;
        if (n == 1)
            return nums[0];

        vector<int> dp(n, 0);

        // base cases
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        // fill dp array iteratively
        for (int i = 2; i < n; i++) {
            int pick = nums[i] + dp[i - 2]; // if we rob current house
            int not_pick = dp[i - 1];       // if we skip current house
            dp[i] = max(pick, not_pick);
        }

        return dp[n - 1];
    }
};