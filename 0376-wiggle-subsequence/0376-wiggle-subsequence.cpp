class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return n;

        int prevDiff = 0;
        int count = 1; // 
        for (int i = 1; i < n; i++) {
            int currDiff = nums[i] - nums[i - 1];

            if ((currDiff > 0 && prevDiff <= 0) || (currDiff < 0 && prevDiff >= 0)) {
                count++;
                prevDiff = currDiff;
            }
        }

        return count;
    }
};