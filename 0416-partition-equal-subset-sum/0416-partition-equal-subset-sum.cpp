class Solution {
public:
    bool solve(vector<int>&nums,int n,int i,int target,int sum,vector<vector<int>>&dp){
        if(i>=n){
            if(sum==target)return true;
            else return false;
        }
        if(sum > target){
            return false;
        }
        if(sum==target)return true;

        if(dp[i][sum]!=-1)return dp[i][sum];

        bool pick=solve(nums,n,i+1,target,sum+nums[i],dp);
        bool nonpick=solve(nums,n,i+1,target,sum,dp);
        return dp[i][sum]=pick||nonpick;
       

    }
    bool canPartition(vector<int>& nums) {
        int total=0;
        for(auto i:nums){
            total+=i;
        }
        if(total%2==0){
            int target=total/2;
            int n=nums.size();
            vector<vector<int>>dp(n,vector<int>(target+1,-1));
            return solve(nums,nums.size(),0,target,0,dp);
        }else{
            return false;
        }
    }
};