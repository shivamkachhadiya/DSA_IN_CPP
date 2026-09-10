class Solution {
public:
    int solve(string s,string t,int i,int j,vector<vector<int>>&dp){
        if(j==t.size())return 1;
        if(i==s.size())return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(s[i]==t[j]){
            return dp[i][j]=solve(s,t,i+1,j+1,dp)+solve(s,t,i+1,j,dp);
        }else{
            return dp[i][j]=solve(s,t,i+1,j,dp);
        }
    }
    int numDistinct(string s, string t) {
        vector<vector<int>>dp(s.size(),vector<int>(t.size(),-1));
        return solve(s, t, 0, 0,dp);
    }
};