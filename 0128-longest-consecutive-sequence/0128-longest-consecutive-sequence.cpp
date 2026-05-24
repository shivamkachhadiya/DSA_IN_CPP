class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;

        sort(nums.begin(),nums.end());
        //1 2 3 4 100 200
        int count=1;
        int maxCount=1;

        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1])continue;
            if(nums[i]+1==nums[i+1]){
                count++;
                maxCount=max(maxCount,count);
            }else{
                count=1;
            }
        }

        return maxCount;
    }
};