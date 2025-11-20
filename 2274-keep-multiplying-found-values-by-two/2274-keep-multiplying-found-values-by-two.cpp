class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        // Create a hash set from the input array for O(1) lookup
        unordered_set<int> numSet(nums.begin(), nums.end());
      
        // Keep doubling the original value while it exists in the set
        while (numSet.count(original)) {
            original *= 2;  // Double the value (equivalent to left shift by 1)
        }
      
        // Return the final value that doesn't exist in the set
        return original;
    }
};