class Solution {
public:
    int solve(string& text1,string& text2,int i,int j,int n1,int n2,vector<vector<int>>&dp){
        if(i>=n1 || j>=n2)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int pick=0;
        if(text1[i]==text2[j]){
            pick=1+solve(text1,text2,i+1,j+1,n1,n2,dp);
        }
        int notpick=max(solve(text1,text2,i+1,j,n1,n2,dp),solve(text1,text2,i,j+1,n1,n2,dp));
        return dp[i][j]=max(pick,notpick);
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n1=text1.size();
        int n2=text2.size();
        vector<vector<int>>dp(n1,vector<int>(n2,-1));
        return solve(text1,text2,0,0,n1,n2,dp);
    }
};