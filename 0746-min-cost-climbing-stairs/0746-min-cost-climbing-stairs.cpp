class Solution {
public:
    int solve(vector<int>& arr, int n, int i,vector<int>&dp) {
        if (i < 0) {
            return 0;
        }
        if (i == 0 || i == 1)
            return arr[i];
        if(dp[i]!=-1)return dp[i];
        return dp[i]=arr[i] + min(solve(arr, n, i - 1,dp), solve(arr, n, i - 2,dp));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>dp(n+1,-1);
        return min(solve(cost,n, n-1,dp), solve(cost, n,n-2,dp));
    }
};