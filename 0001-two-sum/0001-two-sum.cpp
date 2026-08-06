class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;

        for(int i=0;i<nums.size();i++){
            int find_=target-nums[i];
            if(mp.find(find_)!=mp.end()){
                return {i,mp[find_]};
            }
             mp[nums[i]]=i;
        }
        return {};
    }
};