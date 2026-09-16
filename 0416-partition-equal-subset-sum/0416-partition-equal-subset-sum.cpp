class Solution {
public:
    bool solve(vector<int>&arr,int n,int target,int i, vector<vector<int>>&dp){
if(target==0)return true;
if(i>=n)return false;
        if(dp[i][target]!=-1)return dp[i][target];
        bool take=false;
        if(arr[i]<=target)
            take=solve(arr,n,target-arr[i],i+1,dp);
        bool notake=solve(arr,n,target,i+1,dp);

        return dp[i][target]=take||notake;
    }
    bool canPartition(vector<int>& arr) {
        int n=arr.size();
        int sum=0;
        for(auto &x:arr){
            sum+=x;
        }
        int target=sum/2;
        vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        if(sum%2==0){
            return solve(arr,arr.size(),target,0,dp);
        }else{
            return false;
        }
    }
};