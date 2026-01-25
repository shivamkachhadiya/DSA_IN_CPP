#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    int minimumDifference(std::vector<int>& nums, int k) {
        // If we only need to pick 1 student, the difference is always 0
        if (k == 1) return 0;

        // Step 1: Sort the scores
        std::sort(nums.begin(), nums.end());

        int min_diff = INT_MAX;

        // Step 2: Slide a window of size k across the sorted array
        // The window starts at i and ends at i + k - 1
        for (int i = 0; i <= nums.size() - k; ++i) {
            int current_diff = nums[i + k - 1] - nums[i];
            
            // Step 3: Update the global minimum
            if (current_diff < min_diff) {
                min_diff = current_diff;
            }
        }

        return min_diff;
    }
};