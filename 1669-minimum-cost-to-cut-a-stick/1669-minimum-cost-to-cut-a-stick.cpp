class Solution {
public:
    // Recursive function (plain recursion)
    int f(int i, int j, vector<int>& cuts) {
        if (i > j)
            return 0;
        int mini = INT_MAX;
        for (int ind = i; ind <= j; ind++) {
            int cost = cuts[j + 1] - cuts[i - 1] +
                       f(i, ind - 1, cuts) +
                       f(ind + 1, j, cuts);
            mini = min(mini, cost);
        }
        return mini;
    }

    // Memoized version (DP)
    int solve(int i, int j, vector<int>& cuts, vector<vector<int>>& dp) {
        if (i > j)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];

        int mini = INT_MAX;
        for (int ind = i; ind <= j; ind++) {
            int cost = cuts[j + 1] - cuts[i - 1] +
                       solve(i, ind - 1, cuts, dp) +
                       solve(ind + 1, j, cuts, dp);
            mini = min(mini, cost);
        }
        return dp[i][j] = mini;
    }

    int minCost(int n, vector<int>& cuts) {
        int c = cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        sort(cuts.begin(), cuts.end());

        // plain recursion
        // return f(1, c, cuts);

        // dp version
        vector<vector<int>> dp(c + 2, vector<int>(c + 2, -1));
        return solve(1, c, cuts, dp);
    }
};
