class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currsum=nums[0];
        int maxsum=nums[0];
        if(nums.size()==1)return currsum;
        for(int i=1;i<nums.size();i++){
             if(currsum<0){
                currsum=0;
            }
            currsum+=nums[i];
            maxsum=max(maxsum,currsum);
           
        }
        return maxsum;
    }
};