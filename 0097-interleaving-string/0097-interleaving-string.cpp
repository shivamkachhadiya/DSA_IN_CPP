class Solution {
public:
    bool solve(string s1,string s2,string s3,int n1,int n2,int n3,int i,int j,int k,vector<vector<int>>& dp){

        if (i == n3 && j == n1 && k == n2) return true;
        if (i == n3) return false;
        if (dp[j][k] != -1) return dp[j][k];  // already computed
        bool result=false;
        if(j<n1&&s3[i]==s1[j]){
             result=result||solve(s1,s2,s3,n1,n2,n3,i+1,j+1,k,dp);
        }
        if(k<n2&&s3[i]==s2[k]){
             result=result||solve(s1,s2,s3,n1,n2,n3,i+1,j,k+1,dp);
        }
        return dp[j][k]=result;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int n1=s1.size();
        int n2=s2.size();
        int n3=s3.size();
        if(n1+n2!=n3)return false;
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, -1));
        return solve(s1,s2,s3,n1,n2,n3,0,0,0,dp);
    }
};