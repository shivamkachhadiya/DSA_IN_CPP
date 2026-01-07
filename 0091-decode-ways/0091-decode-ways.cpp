class Solution {
public:
    int solve(string s, int n, int i) {
        if (s[i] == '0')
            return 0;

        if (i == n)
            return 1;

        if (i > n)
            return 0;

        int ans = 0;
        // choice 1: take one digit
        ans += solve(s, n, i + 1);

        // choice 2: take two digits (if possible and valid)
        if (i + 1 < n) {
            int num = (s[i] - '0') * 10 + (s[i + 1] - '0');
            if (num >= 10 && num <= 26)
                ans += solve(s, n, i + 2);
        }

        return ans;
    }

    int solveMemo(string& s, int i, vector<int>& dp) {
        if (i == s.size())
            return 1;

        if (s[i] == '0')
            return 0;

        if (dp[i] != -1)
            return dp[i];

        int ans = 0;

        // take one digit
        ans += solveMemo(s, i + 1, dp);

        // take two digits if valid
        if (i + 1 < s.size()) {
            int num = (s[i] - '0') * 10 + (s[i + 1] - '0');
            if (num >= 10 && num <= 26)
                ans += solveMemo(s, i + 2, dp);
        }

        return dp[i] = ans;
    }
    int numDecodings(string s) {
        //int n = s.size();
        //int ans = solve(s, n, 0);
        // return ans;

        // use memoization
        vector<int> dp(s.size(), -1);
        return solveMemo(s, 0, dp);
    }
};