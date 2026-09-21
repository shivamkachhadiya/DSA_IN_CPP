class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int>map;
        for(auto &x:nums){
            map[x]++;
            if(map[x]>1){
                return true;
            }
        }
        return false;
    }
};