class Solution {
public:
    int solve(vector<int>&arr,int n,int curr,int prev,vector<vector<int>>&dp){
        if(curr==n){
            return 0;
        }

        if(dp[curr][prev+1]!=-1){
            return dp[curr][prev+1];
        }

        int take=0;
        if(prev==-1||arr[curr]>arr[prev]){
            take=1+solve(arr,n,curr+1,curr,dp);
        }

        int notake=0+solve(arr,n,curr+1,prev,dp);

        return dp[curr][prev+1]=max(take,notake);
    }
    int lengthOfLIS(vector<int>& nums) {
     int n=nums.size();
     vector<vector<int>>dp(n,vector<int>(n+1,-1));
     return solve(nums,n,0,-1,dp);
    }
};