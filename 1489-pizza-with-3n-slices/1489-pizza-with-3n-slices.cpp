class Solution {
public:
    int solveRec(int index, vector<int>& slices, int n) {
        if (n == 0 || index >= slices.size()) {
            return 0;
        }
        int take = slices[index] + solveRec(index + 2, slices, n - 1);
        int noTake = 0 + solveRec(index + 1, slices, n);
        return max(take, noTake);
    }

    int solve(int index, int end, vector<int>& slices, int n,
              vector<vector<int>>& dp) {
        if (n == 0 || index > end) {
            return 0;
        }
        if (dp[index][n] != -1)
            return dp[index][n];

        int take = slices[index] + solve(index + 2, end, slices, n - 1, dp);
        int noTake = solve(index + 1, end, slices, n, dp);

        return dp[index][n] = max(take, noTake);
    }

    int maxSizeSlices(vector<int>& slices) {
        //----------------------recursive------------------------
        // int k=slices.size();
        // int case1=solveRec(0,slices,k/3);
        // int case2=solveRec(1,slices,k/3);
        // return max(case1,case2);

        //----------------------memoization-----------------------
        int k = slices.size();
        int n = k / 3;

        // Case 1: use [0 .. k-2]
        vector<vector<int>> dp1(k, vector<int>(n + 1, -1));
        int case1 = solve(0, k - 2, slices, n, dp1);

        // Case 2: use [1 .. k-1]
        vector<vector<int>> dp2(k, vector<int>(n + 1, -1));
        int case2 = solve(1, k - 1, slices, n, dp2);

        return max(case1, case2);
    }
};