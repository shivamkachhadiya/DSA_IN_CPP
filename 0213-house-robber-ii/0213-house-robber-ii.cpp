class Solution {
public:
    int solve(vector<int>&arr,int n,int i,vector<int>&dp){
        if(i>=n)return 0;
        if(dp[i]!=-1)return dp[i];
        int take=arr[i]+solve(arr,n,i+2,dp);
        int notake=0+solve(arr,n,i+1,dp);
        return dp[i]=max(take,notake);
    }
    int rob(vector<int>& nums) {

        int n=nums.size();
        if(n==1)return nums[0];
        vector<int>dp1(n,-1);
        int ans1=solve(nums,n-1,0,dp1);
        vector<int>dp2(n,-1);
        int ans2=solve(nums,n,1,dp2);
        return max(ans1,ans2);
    }
};