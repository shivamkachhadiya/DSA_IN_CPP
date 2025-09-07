#define MOD 1000000007
class Solution {
  public:
    int add(int a,int b){
        return (a%MOD+b%MOD)%MOD;
    }
    
    int mul(int a,int b){
        return ((a%MOD)*(b%MOD))%MOD;
    }
    int solveMem(int n,int k,vector<int>&dp){
        if(n==1)return k;
        if(n==2)return add(k,mul(k,k-1));
        if(dp[n]!=-1)return dp[n];
        dp[n]=add(mul(solveMem(n-2,k,dp),k-1),mul(solveMem(n-1,k,dp),k-1));
        return dp[n];
    }
    int countWays(int n, int k) {
        // code here
        vector<int>dp(n+1,-1);
                return solveMem(n, k, dp); // fixed function call

    }
};