class Solution {
public:
    int solve(string &a,string &b,int i,int j,int n1,int n2,vector<vector<int>>&dp){
        if(i>=n1||j>=n2)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(a[i]==b[j]){
            return dp[i][j]=1+solve(a,b,i+1,j+1,n1,n2,dp);
        }else{
            return dp[i][j]=max(solve(a,b,i+1,j,n1,n2,dp),solve(a,b,i,j+1,n1,n2,dp));
        }
    }
    int longestPalindromeSubseq(string s) {
        string s2=s;
        reverse(s2.begin(),s2.end());
        int n1=s.size();
        int n2=s.size();
        vector<vector<int>>dp(n1+1,vector<int>(n2+1,-1));
        return solve(s,s2,0,0,n1,n2,dp);
    }
};