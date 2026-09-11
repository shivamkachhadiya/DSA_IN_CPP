class Solution {
public:
    int solve(string s, vector<string>& arr, unordered_set<string>& st, int i,
              int n, vector<int>& dp) {
        if (i == n)
            return 0;
        if (dp[i] != -1)
            return dp[i];
        int no_extra = 1e9;
        for (int j = i; j<n; j++) {
            string temp = s.substr(i, j-i+1);
            if (st.find(temp) != st.end()) {
                no_extra = min(no_extra, solve(s, arr, st, j+1, n, dp));
            }
        }
        int take_extra = 1 + solve(s, arr, st, i + 1, n, dp);
        return dp[i] = min(no_extra, take_extra);
    }
    int minExtraChar(string s, vector<string>& arr) {
        unordered_set<string> st(arr.begin(), arr.end());
        vector<int> dp(s.size(), -1);
        return solve(s, arr, st, 0, s.size(), dp);
    }
};