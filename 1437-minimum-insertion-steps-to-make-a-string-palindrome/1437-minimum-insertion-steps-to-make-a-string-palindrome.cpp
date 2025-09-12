class Solution {
public:
    int solve(string &text1,string &text2,int n1,int n2,int i,int j,vector<vector<int>>&dp){
        if (i >= n1 || j >= n2) return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(text1[i]==text2[j]){
            return 1+solve(text1,text2,n1,n2,i+1,j+1,dp);
        }
        else{
            dp[i][j]= max(solve(text1,text2,n1,n2,i+1,j,dp),solve(text1,text2,n1,n2,i,j+1,dp));
        }
        return dp[i][j];
    }
    int longestPalindromeSubseq(string s) {
        string s2=s;
        reverse(s.begin(), s.end());
        int n1=s.size();
        int n2=s2.size();
        int i=0;
        int j=0;
        vector<vector<int>>dp(n1,vector<int>(n2,-1));
        return solve(s,s2,n1,n2,i,j,dp);

    }
    int minInsertions(string s) {
        return s.size()-longestPalindromeSubseq(s);
    }
};