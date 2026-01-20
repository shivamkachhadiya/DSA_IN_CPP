class Solution {
public:
    inline int atMost(vector<int>& nums, int k)const {
        if (k < 0)
            return 0;

        int l = 0, sum = 0, count = 0;
        for (int r = 0; r < nums.size(); r++) {
            sum += nums[r];

            while (sum > k) {
                sum -= nums[l];
                l++;
            }

            count += (r - l + 1); // all valid subarrays ending at r
        }
        return count;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atMost(nums, goal) - atMost(nums, goal - 1);
    }
};