class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        unordered_map<int, int> count;
        
        // Step 1: Count remainders
        for (int x : nums) {
            int r = ((x % value) + value) % value;  // handle negative numbers
            count[r]++;
        }

        // Step 2: Simulate MEX
        for (int i = 0; ; i++) {
            int r = i % value;
            if (count[r] > 0) {
                count[r]--;  // we can represent this number
            } else {
                return i;  // first missing number
            }
        }
    }
};
