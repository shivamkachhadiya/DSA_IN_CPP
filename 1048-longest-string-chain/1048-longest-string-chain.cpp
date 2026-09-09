class Solution {
public:
    int n;
    static bool myFunction(string& word1, string& word2) {
        return word1.length() < word2.length();
    }

    bool isPred(string& prev, string& curr) {
        int M = prev.length();
        int N = curr.length();
        if (M >= N || N - M != 1)
            return false;
        int i = 0, j = 0;
        while (i < M && j < N) {
            if (prev[i] == curr[j]) {
                i++;
            }
            j++;
        }
        return i == M;
    }

    int lis(vector<string>& words, int p, int i, vector<vector<int>>& dp) {
        if (i >= n) {
            return 0;
        }
        if (dp[i][p + 1] != -1)
            return dp[i][p + 1];
        int take = 0;
        if (p == -1 || isPred(words[p], words[i])) {
            take = 1 + lis(words, i, i + 1, dp);
        }
        int notake = lis(words, p, i + 1, dp);
        return dp[i][p + 1] = max(take, notake);
    }
    int longestStrChain(vector<string>& words) {
        n = words.size();
        sort(begin(words), end(words), myFunction);
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return lis(words, -1, 0, dp);
    }
};