class Solution {
public:
    int solve(vector<int>& arr, int tar, vector<int>& dp) {
        if (tar == 0) return 0;
        if (tar < 0) return INT_MAX;

        if (dp[tar] != -1) return dp[tar];

        int mini = INT_MAX;
        for (int coin : arr) {
            int ans = solve(arr, tar - coin, dp);
            if (ans != INT_MAX) {
                mini = min(mini, 1 + ans);
            }
        }

        return dp[tar] = mini;
    }

    int findMin(int tar) {
        vector<int> arr = {1, 2, 5, 10};
        vector<int> dp(tar + 1, -1);

        int ans = solve(arr, tar, dp);
        return (ans == INT_MAX) ? -1 : ans;
    }
};
