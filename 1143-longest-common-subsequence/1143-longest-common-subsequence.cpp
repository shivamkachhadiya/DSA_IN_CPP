class Solution {
public:
    int solve(string &text1, string &text2, int n1, int n2, int i, int j,
              vector<vector<int>>& dp) {
        if (i >= n1 || j >= n2)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int ans = 0;
        if (text1[i] == text2[j]) {
            ans = 1 + solve(text1, text2, n1, n2, i + 1, j + 1, dp);
        } else {
            ans = max((solve(text1, text2, n1, n2, i + 1, j, dp)),
                      (solve(text1, text2, n1, n2, i, j + 1, dp)));
        }
        return dp[i][j] = ans;
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size();
        int n2 = text2.size();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, -1));
        return solve(text1, text2, n1, n2, 0, 0, dp);
    }
};