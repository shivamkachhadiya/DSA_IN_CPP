class Solution {
public:
    int solve(int target, vector<int>& arr, int i, vector<vector<int>>& dp) {
        if (i == 0) {
            return (target % arr[0] == 0);
        }

        if (dp[i][target] != -1)
            return dp[i][target];

        int take = 0;
        if (arr[i] <= target) {
            take = solve(target - arr[i], arr, i, dp);
        }
        int notake = 0 + solve(target, arr, i - 1, dp);
        return dp[i][target] = take + notake;
    }



int change(int amount, vector<int>& coins) {
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
    return solve(amount, coins,n-1, dp);
}
};
