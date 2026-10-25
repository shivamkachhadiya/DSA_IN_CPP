class Solution {
public:
    int solve(string &a,string &b,int i,int j,vector<vector<int>>&dp){
        if(i==a.length()){
            return b.length()-j;    
        }

        if(j==b.length()){
            return a.length()-i;
        }

        if(dp[i][j]!=-1)return dp[i][j];

        int ans=0;

        if(a[i]==b[j]){
            return dp[i][j]=solve(a,b,i+1,j+1,dp);
        }else{

            int insert_ans=1+solve(a,b,i,j+1,dp);

            int delete_ans=1+solve(a,b,i+1,j,dp);

            int replace_ans=1+solve(a,b,i+1,j+1,dp);

            ans=min({insert_ans,delete_ans,replace_ans});
        }
        return dp[i][j]=ans;
    }
    int minDistance(string word1, string word2) {
        int n1=word1.size();
        int n2=word2.size();
        vector<vector<int>>dp(n1+1,vector<int>(n2+1,-1));
        return solve(word1,word2,0,0,dp);
    }
};