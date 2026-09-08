class Solution {
public:
    int solve(int target,vector<int>&arr,int n,int currsum,int i,vector<vector<int>>&dp){
        if(i>=n){
            if(currsum==target){
                return 1;
            }
            return 0;
        }
        if(currsum>target)return 0;
        if(dp[i][currsum]!=-1)return dp[i][currsum];
        int take=solve(target,arr,n,currsum+arr[i],i,dp);
        int notake=solve(target,arr,n,currsum,i+1,dp);
        return dp[i][currsum]=take+notake;
    }
    int change(int amount, vector<int>& arr) {
        int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return solve(amount,arr,n,0,0,dp);
    }
};