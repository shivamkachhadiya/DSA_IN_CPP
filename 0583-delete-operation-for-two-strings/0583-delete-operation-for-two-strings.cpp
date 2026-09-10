class Solution {
public:
    int solve(string a,string b,int i,int j,vector<vector<int>>&dp){
        if(i>=a.size()||j>=b.size())return 0;
        
        if(dp[i][j]!=-1)return dp[i][j];
        int ans=0;

        if(a[i]==b[j]){
            ans=1+solve(a,b,i+1,j+1,dp);
        }else{
            ans=max(solve(a,b,i+1,j,dp),solve(a,b,i,j+1,dp));
        }
        return dp[i][j]=ans;
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>>dp(word1.size(),vector<int>(word2.size(),-1));
        int finslcs=solve(word1,word2,0,0,dp);
        return word1.size()-finslcs+word2.size()-finslcs;
    }
};