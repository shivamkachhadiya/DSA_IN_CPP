class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {

        int n = nums.size();
        int maxCount = 0;
        int left = 0;

        for (int right = 0; right < n; right++) {

            if (nums[right] == 0) {
                k--;
            }

            while (k < 0) {
                if (nums[left] == 0) {
                    k++;
                }
                left++;
            }

            maxCount = max(maxCount, right - left + 1);
        }

        return maxCount;
    }
};