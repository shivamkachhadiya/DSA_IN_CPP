class Solution {
public:
    int solve(string word1, string word2, int n1, int n2, int i, int j,vector<vector<int>>&dp) {
        if (i >= n1 || j >= n2)
            return 0;
        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        int pick = 0;
        if (word1[i] == word2[j]) {
            pick = 1 + solve(word1, word2, n1, n2, i + 1, j + 1,dp);
        }
        int nonpick = max(solve(word1, word2, n1, n2, i + 1, j,dp),
                          solve(word1, word2, n1, n2, i, j + 1,dp));
        return dp[i][j]=max(pick, nonpick);
    }
    int minDistance(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();
        vector<vector<int>>dp(n1,vector<int>(n2,-1));
        return word1.size()+word2.size()-2*solve(word1, word2, n1, n2, 0, 0,dp);

    }
};