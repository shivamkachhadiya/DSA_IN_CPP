class Solution {
public:
    int solve(string &s1,string &s2,int n1,int n2,int i,int j,vector<vector<int>>&dp){
        if(i==n1||j==n2)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(s1[i]==s2[j]){
            return dp[i][j]=1+solve(s1,s2,n1,n2,i+1,j+1,dp);
        }
        return dp[i][j]=max(solve(s1,s2,n1,n2,i+1,j,dp),solve(s1,s2,n1,n2,i,j+1,dp));
    }
    int longestPalindromeSubseq(string s1) {
        string s2=s1;
        int n=s1.size();
        reverse(s2.begin(),s2.end());
        //now s1=bbbab
        //    s2=babbb
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return solve(s1,s2,s1.size(),s2.size(),0,0,dp);
    }
};