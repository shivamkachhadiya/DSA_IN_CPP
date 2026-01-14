class Solution {
  public:
    int solve(string &s1,string &s2,int n1,int n2,int i,int j,vector<vector<int>>&dp){
        if(i==n1||j==n2)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int ans=0;
        if(s1[i]==s2[j]){
            ans=1+solve(s1,s2,n1,n2,i+1,j+1,dp);
        }else{
            ans=max(solve(s1,s2,n1,n2,i+1,j,dp),solve(s1,s2,n1,n2,i,j+1,dp));
        }
        return dp[i][j]=ans;
    }
    int lcs(string &s1, string &s2) {
        // code here
        int n1=s1.size();
        int n2=s2.size();
        vector<vector<int>>dp(n1,vector<int>(n2,-1));
        return solve(s1,s2,n1,n2,0,0,dp);
    }
};
