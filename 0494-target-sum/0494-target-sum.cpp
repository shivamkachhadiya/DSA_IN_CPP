class Solution {
public:
    int count=0;
    void solve(vector<int>& nums,int n,int target,int currSum,int i){
        if(i>=n){
        if(currSum==target){
            count++;
            return;
        }
        return;
        }
        solve(nums,n,target,currSum+nums[i],i+1);
        solve(nums,n,target,currSum-nums[i],i+1);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
         solve(nums,n,target,0,0);
         return count;
    }
};