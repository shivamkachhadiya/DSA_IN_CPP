class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // sort 1 2 3 4 100 200
        int count = 1;
        if (nums.empty())
            return 0;

        sort(nums.begin(), nums.end());
        int maxCount = 1;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1])
                continue;
            if (nums[i - 1] + 1 == nums[i])
                count++;
            else {
                count = 1;
            }
            maxCount = max(maxCount, count);
        }
        return maxCount;
    }
};