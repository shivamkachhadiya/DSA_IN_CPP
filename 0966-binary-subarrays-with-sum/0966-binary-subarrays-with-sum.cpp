class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int> prefixCount;
        prefixCount[0] = 1;
        
        int sum = 0, res = 0;
        for (int num : nums) {
            sum += num;
            res += prefixCount[sum - goal];
            prefixCount[sum]++;
        }
        return res;
    }
};
