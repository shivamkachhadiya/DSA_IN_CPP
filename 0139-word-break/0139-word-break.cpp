class Solution {
public:
    int n;
    bool solve(int idx, string &s, unordered_set<string>& st, vector<int>& dp) {
        if(idx == n) return true;
        if(dp[idx] != -1) return dp[idx];  // already computed

        for(int len = 1; len <= n; len++) {
            string temp = s.substr(idx, len);
            if(st.find(temp) != st.end() && solve(idx + len, s, st, dp)) {
                return dp[idx] = true;
            }
        }
        return dp[idx] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        n = s.size();
        vector<int> dp(n, -1);  // -1 = not computed
        return solve(0, s, st, dp);
    }
};
