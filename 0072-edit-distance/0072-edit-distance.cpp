class Solution {
public:
    int solve(string &w1,string &w2,int n1,int n2,int i,int j,vector<vector<int>>&dp){
        if(i==n1){
            return n2-j;
        }
        if(j==n2){
            return n1-i;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        int ans=0;
        if(w1[i]==w2[j]){
            return solve(w1,w2,n1,n2,i+1,j+1,dp);
        }else{
            int insertAns=1+solve(w1,w2,n1,n2,i,j+1,dp);
            int deleteAns=1+solve(w1,w2,n1,n2,i+1,j,dp);
            int replaceAns=1+solve(w1,w2,n1,n2,i+1,j+1,dp);
             ans=min({insertAns,deleteAns,replaceAns});
        }
        return dp[i][j]=ans;
    }
    int minDistance(string word1, string word2) {
        int n1=word1.size();
        int n2=word2.size();
        vector<vector<int>>dp(n1+1,vector<int>(n2+1,-1));
        return solve(word1,word2,n1,n2,0,0,dp);
    }
};