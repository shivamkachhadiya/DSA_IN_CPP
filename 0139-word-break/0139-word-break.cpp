class Solution {
public:
    bool solve(int start, string s, unordered_set<string>& st) {

        // whole string consumed
        if (start == s.size())
            return true;

        string temp = "";

        for (int i = start; i < s.size(); i++) {

            temp += s[i];

            // word found in dictionary
            if (st.find(temp) != st.end()) {

                // check remaining part
                if (solve(i + 1, s, st))
                    return true;
            }
        }

        return false;
    }

    bool solveMemo(int start, string s, unordered_set<string>& st,vector<int>& dp) {

        // whole string consumed
        if (start == s.size())
            return true;

        if(dp[start]!=-1)return dp[start];

        string temp = "";

        for (int i = start; i < s.size(); i++) {

            temp += s[i];

            // word found in dictionary
            if (st.find(temp) != st.end()) {

                // check remaining part
                if (solveMemo(i + 1, s, st, dp))
                    return dp[start]=true;
            }
        }

        return dp[start]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {

        unordered_set<string> st(wordDict.begin(), wordDict.end());

        vector<int> dp(s.size(), -1);

        return solveMemo(0, s, st,dp);
    }
};