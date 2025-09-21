class Solution {
public:
    static bool cmp(string &a, string &b) {
        return a.size() < b.size();
    }

    bool isPredecessor(string &a, string &b) {
        if (b.size() != a.size() + 1) return false;
        int i = 0, j = 0;
        while (i < a.size() && j < b.size()) {
            if (a[i] == b[j]) {
                i++; j++;
            } else {
                j++;
            }
        }
        return i == a.size();
    }

    int solve(int prev, int curr, vector<string>& words, vector<vector<int>>& dp) {
        if (curr == words.size()) return 0;

        if (dp[prev + 1][curr] != -1) return dp[prev + 1][curr];

        // Option 1: Take current word if valid
        int take = 0;
        if (prev == -1 || isPredecessor(words[prev], words[curr])) {
            take = 1 + solve(curr, curr + 1, words, dp);
        }

        // Option 2: Skip current word
        int skip = solve(prev, curr + 1, words, dp);

        return dp[prev + 1][curr] = max(take, skip);
    }

    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), cmp);
        int n = words.size();

        // dp[prev+1][curr]
        vector<vector<int>> dp(n + 1, vector<int>(n, -1));

        return solve(-1, 0, words, dp);
    }
};
