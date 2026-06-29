class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>freq;
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            freq[nums[i]]=i;
        }
        for(int i=0;i<nums.size();i++){
            int rem = target - nums[i];
            if(freq.find(rem) != freq.end() && freq[rem] != i){
                ans.push_back(i);
                ans.push_back(freq[rem]);
                break;
            }
        }
        return ans;
    }
};