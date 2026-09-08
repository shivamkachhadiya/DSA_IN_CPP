class Solution {
public:
    int solve(vector<int>& arr, int target, int sum, vector<int>& dp) {
        if(sum == target) return 1;   // ek valid way mila
        if(sum > target) return 0;    // target cross ho gaya

        if(dp[sum] != -1) return dp[sum];  // memoization check

        int ans = 0;
        for(int i = 0; i < arr.size(); i++) {
            ans += solve(arr, target, sum + arr[i], dp);
        }
        return dp[sum] = ans;
    }

    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1, -1);  // memo table
        return solve(nums, target, 0, dp);
    }
};
