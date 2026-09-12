class Solution {
public:
    int solve(int i, int buy, vector<int>& arr, vector<vector<vector<int>>>&dp,
              int limit) {
        if (i == arr.size())
            return 0;
        if (limit == 0)
            return 0;
        int profit = 0;
        if (dp[i][buy][limit] != -1)
            return dp[i][buy][limit];
        if (buy) {
            profit = max((-arr[i] + solve(i + 1, 0, arr, dp,limit)),
                         (0 + solve(i + 1, 1, arr, dp,limit)));
        } else {
            profit = max((+arr[i] + solve(i + 1, 1, arr, dp,limit-1)),
                         (0 + solve(i + 1, 0, arr, dp,limit)));
        }
        return dp[i][buy][limit]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return solve(0, 1, prices, dp,2);
    }
};