class Solution {
public:
    int solve(string &a,string &b,int n1,int n2,int i,int j,vector<vector<int>>&dp){
        if(i>=n1||j>=n2)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(a[i]==b[j]){
            return dp[i][j]=1+solve(a,b,n1,n2,i+1,j+1,dp);
        }else{
            return dp[i][j]=max(solve(a,b,n1,n2,i+1,j,dp),solve(a,b,n1,n2,i,j+1,dp));
        }
    }
    int minDistance(string word1, string word2) {
        int n1=word1.size();
        int n2=word2.size();
        vector<vector<int>>dp(n1+1,vector<int>(n2+1,-1));
        int final_ans=solve(word1,word2,n1,n2,0,0,dp);
        return n1-final_ans+n2-final_ans;
    }
};