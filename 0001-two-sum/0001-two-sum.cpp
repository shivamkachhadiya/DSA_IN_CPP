class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> pairs;
        
        for(int i = 0; i < nums.size(); i++) {
            pairs.push_back({nums[i], i});
        }
        
        sort(pairs.begin(), pairs.end());
        
        int left = 0;
        int right = pairs.size() - 1;
        
        while(left < right) {
            int sum = pairs[left].first + pairs[right].first;
            
            if(sum == target) {
                return {pairs[left].second, pairs[right].second};
            }
            else if(sum < target) {
                left++;
            }
            else {
                right--;
            }
        }
        
        return {};  // No solution found
    }
};