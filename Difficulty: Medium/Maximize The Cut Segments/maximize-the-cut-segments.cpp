class Solution {
  public:
    int solveMem(int n,int x,int y,int z,vector<int>&dp){
        if(n==0)return 0;
        if(n<0)return INT_MIN;
        if(dp[n]!=-1)return dp[n];
        int a=solveMem(n-x,x,y,z,dp)+1;
        int b=solveMem(n-y,x,y,z,dp)+1;
        int c=solveMem(n-z,x,y,z,dp)+1;
        dp[n]=max(a,max(b,c));
        return dp[n];
    }
    // Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z) {
        // Your code here
        vector<int>dp(n+1,-1);
        int ans=solveMem(n,x,y,z,dp);
        if(ans<0)return 0;
        else return ans;
        
    }
};