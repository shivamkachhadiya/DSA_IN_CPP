class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int sum = 0;
        int minAns = INT_MAX;
        for (int r = 0; r < n; r++) {
            sum += nums[r];

            while (sum >= target) {
                minAns=min(minAns,r-left+1);
                sum -= nums[left];
                left++;
            }

            if (sum == target) {
                minAns = min(minAns, r - left + 1);
            }
        }
        if(minAns==INT_MAX)return 0;
        else return minAns;
    }
};