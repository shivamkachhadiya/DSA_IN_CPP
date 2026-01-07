class Solution {
public:
    int solve(vector<int>&arr,int tar,int n,vector<long long>&dp){
         if(tar<0)return 0;
        if(tar==0)return 1;
        if (dp[tar] != -1) return dp[tar];

        long long ans = 0;

        for(int i=0;i<n;i++){
            ans+=solve(arr,tar-arr[i],n,dp);
        }
        return dp[tar]=ans;

        
    }
    int combinationSum4(vector<int>& nums, int target) {
        int n=nums.size();
        vector<long long>dp(target+1,-1);
        return (int)solve(nums,target,n,dp);
    }
};