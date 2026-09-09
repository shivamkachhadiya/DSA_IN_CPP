class Solution {
public:
    int solve(vector<int>&arr,int target,int i,int n,vector<vector<int>>&dp){
        if(target==0)return 1;
        if(target<0)return 0;
        if(i>=n){
            if(target==0){
                return 1;
            }
            return 0;
        }
        if(dp[i][target]!=-1)return dp[i][target];
        int take=solve(arr,target-arr[i],0,n,dp);
        int notake=solve(arr,target,i+1,n,dp);

        return dp[i][target]=take+notake;
    }
    int combinationSum4(vector<int>& arr, int target) {
        int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        return solve(arr,target,0,arr.size(),dp);
    }
};