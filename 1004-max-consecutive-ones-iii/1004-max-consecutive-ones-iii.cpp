class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0, right = 0;
        int zeros = 0;
        int maxLength = 0;
        while (right < n) {
            if (nums[right] == 1) {
                int currLength = right - left + 1;
                maxLength = max(maxLength, currLength);
                right++;
            } else if (nums[right] == 0) {
                zeros++;
                if (zeros <= k) {
                    int currLength = right - left + 1;
                    maxLength = max(maxLength, currLength);
                    right++;
                } else {
                    while (zeros != k) {
                        if (nums[left] == 0) {
                            zeros--;
                            left++;
                        } else {
                            left++;
                        }
                    }
                    int currLength = right - left + 1;
                    maxLength = max(maxLength, currLength);
                    right++;
                }
            }
        }
        return maxLength;
    }
};