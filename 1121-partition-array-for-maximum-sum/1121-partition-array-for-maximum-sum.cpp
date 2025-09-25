class Solution {
public:
    int solve(vector<int>& arr, int k, int n, int i) {
        if (i == n)
            return 0;

        int max_ans;
        int len = 0, maxi = INT_MIN;
        int sum = 0;
        for (int j = i; j < min(n, i + k); j++) {
            len++;
            maxi = max(maxi, arr[j]);
            sum = (len * maxi) + solve(arr, k, n, j + 1);
            max_ans = max(max_ans, sum);
        }
        return max_ans;
    }
    
    int solveMEM(vector<int>& arr, int k, int n, int i,vector<int>&dp) {
        if (i == n)
            return 0;
        if(dp[i]!=-1)return dp[i];

        int max_ans = INT_MIN;  
        int len = 0, maxi = INT_MIN;
        int sum = 0;
        for (int j = i; j < min(n, i + k); j++) {
            len++;
            maxi = max(maxi, arr[j]);
            sum = (len * maxi) + solveMEM(arr, k, n, j + 1,dp);
            max_ans = max(max_ans, sum);
        }
        return dp[i] = max_ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        // return solve(arr,k,n,0);
        //==========MEMOIZATION====================
        vector<int> dp(n + 1, -1); 
        return solveMEM(arr, k, n, 0, dp);
    }
};