class Solution {
public:
    int solve(string &t1,string &t2,int n1,int n2,int i,int j,vector<vector<int>>&dp){
       if(i>=n1 || j>=n2)return 0;
       if(dp[i][j]!=-1)return dp[i][j];
        int take=0;
        if(t1[i]==t2[j]){
            take=1+solve(t1,t2,n1,n2,i+1,j+1,dp);
        }
        int notake= max(solve(t1,t2,n1,n2,i+1,j,dp),solve(t1,t2,n1,n2,i,j+1,dp));
        return dp[i][j]=max(take,notake);
        
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n1=text1.size();
        int n2=text2.size();
        vector<vector<int>>dp(n1,vector<int>(n2,-1));
        return solve(text1,text2,n1,n2,0,0,dp);
    }
};