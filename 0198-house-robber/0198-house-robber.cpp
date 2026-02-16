class Solution {
public:
    int solve(vector<int>&arr,int n,int i,vector<int>&dp){
        if(i<0){
            return 0;
        }
        if(i==0){
            return arr[0];
        }

        if(dp[i]!=-1)return dp[i];

        int pick=arr[i]+solve(arr,n,i-2,dp);
        int nonpick=0+solve(arr,n,i-1,dp);
        return dp[i]=max(pick,nonpick);
    }
    int rob(vector<int>& nums) {
         int n=nums.size();
         vector<int>dp(n+1,-1);
        return solve(nums,n,n-1,dp);
    }
};