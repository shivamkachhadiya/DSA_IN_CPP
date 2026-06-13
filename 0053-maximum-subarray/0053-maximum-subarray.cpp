class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0;
        int maxSum=nums[0];
        if(nums.size()==1)return nums[0];
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            maxSum=max(sum,maxSum);
            if(sum<0){
                sum=0;
               
            }
        }
        return maxSum;
    }
};