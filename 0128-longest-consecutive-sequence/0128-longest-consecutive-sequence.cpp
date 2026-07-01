class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;

        sort(nums.begin(), nums.end());
        // 1 2 3 4 100 200
        // 0 1 1 2
        int count = 0;
        int current_count = 0;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1] + 1) {
                current_count++;
                count = max(count, current_count);
            } else if (nums[i] == nums[i - 1]) {
                continue;
            } else {
                current_count = 0;
                count = max(count, current_count);
            }
        }
        return count+1;
    }
};