
class Solution {
public:
    bool solve(vector<int>& arr, int n, int i, int target,
               int currSum, vector<vector<int>>& dp) {

        if(currSum == target) return true;

        if(i >= n || currSum > target) return false;

        if(dp[i][currSum] != -1)
            return dp[i][currSum];

        int take = solve(arr, n, i+1, target,
                         currSum + arr[i], dp);

        int notake = solve(arr, n, i+1, target,
                           currSum, dp);

        return dp[i][currSum] = take || notake;
    }

    bool canPartition(vector<int>& nums) {

        int n = nums.size();

        int sum = accumulate(nums.begin(), nums.end(), 0);

        if(sum % 2 != 0) return false;

        int target = sum / 2;

        vector<vector<int>> dp(n, vector<int>(target+1, -1));

        return solve(nums, n, 0, target, 0, dp);
    }
};
