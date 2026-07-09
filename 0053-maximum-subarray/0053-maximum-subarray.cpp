class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currsum=nums[0];
        int maxsum=INT_MIN;
        if(nums.size()==1)return currsum;
        for(int i=0;i<nums.size();i++){
            currsum+=nums[i];
            maxsum=max(maxsum,currsum);
            if(currsum<0){
                currsum=0;
            }
        }
        return maxsum;
    }
};