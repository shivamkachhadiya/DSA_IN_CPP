class Solution {
public:
    int solve(string s,int i,int n,vector<int>&dp){
        if(i==n)return 1;
        if(s[i]-'0'==0)return 0;
        if(dp[i]!=-1)return dp[i];
        int one_break=solve(s,i+1,n,dp);
        int two_break=0;
        if(i+1<n){
            int num=(s[i]-'0')*10+(s[i+1]-'0');
            if(num>=10&&num<=26)
                two_break=solve(s,i+2,n,dp);
        }
        return dp[i]=one_break+two_break;
    }
    int numDecodings(string s) {
        int n=s.size();
        vector<int>dp(102,-1);
        return solve(s,0,s.size(),dp);
    }
};