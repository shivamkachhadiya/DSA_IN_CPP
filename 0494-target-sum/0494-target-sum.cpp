class Solution {
public:
    int count = 0;
    void solve(vector<int>&arr,int target,int n,int i,int sum){
        if(i>=n){
            if(sum==target){
                count++;
                return;
            }else{
                return;
            }
        }
        
        solve(arr,target,n,i+1,sum+arr[i]);
        solve(arr,target,n,i+1,sum-arr[i]);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        solve(nums,target,nums.size(),0,0);
        return count;
    }
};