class Solution {
public:
    int solve(vector<int>& arr, int i, int end,vector<int>&dp) {
        if (i > end)
            return 0;
        if(dp[i]!=-1)return dp[i];
        int take = arr[i] + solve(arr, i + 2, end,dp);
        int notake = 0 + solve(arr, i + 1, end,dp);
        return dp[i]=max(take, notake);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        vector<int>dp1(n,-1);
                vector<int>dp2(n,-1);

        int takefirst = solve(nums, 0, n - 2,dp1);
        int notakefirst = solve(nums, 1, n - 1,dp2);
        return max(takefirst, notakefirst);
    }
};