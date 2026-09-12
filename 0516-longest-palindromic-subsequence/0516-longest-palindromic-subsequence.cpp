class Solution {
public:
    int solve(string &s, string &temp, int i, int j, vector<vector<int>>& dp) {
        if (i == s.size() || j == temp.size())
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];

        int take = 0;
        if (s[i] == temp[j]) {
            take = 1 + solve(s, temp, i + 1, j + 1, dp);
        }
        int notake = max(solve(s, temp, i + 1, j, dp),
                         solve(s, temp, i, j + 1, dp));

        return dp[i][j] = max(take, notake);
    }

    int longestPalindromeSubseq(string s) {
        string temp = s;
        reverse(temp.begin(), temp.end());
        int n = s.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));  //  dynamic size
        return solve(s, temp, 0, 0, dp);
    }
};
