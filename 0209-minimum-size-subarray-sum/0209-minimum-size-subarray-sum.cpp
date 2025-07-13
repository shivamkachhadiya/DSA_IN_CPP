class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int minLen = INT_MAX;
        int start = 0, sum = 0;

        for (int end = 0; end < n; end++) {
            sum += nums[end];

            while (sum >= target) {
                minLen = min(minLen, end - start + 1);
                sum -= nums[start++];
            }
        }

        return (minLen == INT_MAX) ? 0 : minLen;
    }
};
