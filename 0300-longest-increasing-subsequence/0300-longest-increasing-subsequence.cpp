class Solution {
public:
    int solve(int n, vector<int>& a, int curr, int prev,
              vector<vector<int>>& dp) {
        if (curr == n) {
            return 0;
        }
        if (dp[curr][prev + 1] != -1)
            return dp[curr][prev + 1];
        // include
        int take = 0;
        if (prev == -1 || a[curr] > a[prev]) {
            take = 1 + solve(n, a, curr + 1, curr, dp);
        }

        // exclude
        int nottake = 0 + solve(n, a, curr + 1, prev, dp);

        dp[curr][prev + 1] = max(take, nottake);
        return dp[curr][prev + 1];
    }

    // Optimal LIS using Binary Search + Greedy
    int solveOptimal(int n, vector<int>&a) {
        if (n == 0)
            return 0;

        vector<int> ans;
        ans.push_back(a[0]);

        for (int i = 1; i < n; i++) {
            if (a[i] > ans.back()) {
                // If current element is greater than last element in ans,
                // append it
                ans.push_back(a[i]);
            } else {
                // Find index of the smallest element >= a[i] and replace it
                int index =
                    lower_bound(ans.begin(), ans.end(), a[i]) - ans.begin();
                ans[index] = a[i];
            }
        }
        return ans.size(); // length of LIS
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        // vector<vector<int>>dp(n,vector<int>(n+1,-1));
        // return solve(n,nums,0,-1,dp);

        return solveOptimal(n, nums);
    }
};