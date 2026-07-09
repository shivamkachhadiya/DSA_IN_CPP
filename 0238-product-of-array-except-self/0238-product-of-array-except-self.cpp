class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prod = 1;
        int countZeros = 0;
        for (auto i : nums) {
            if (i == 0) {
                countZeros++;
            } else {
                prod *= i;
            }
        }
        int n = nums.size();
        vector<int> ans(n);

        if(countZeros>1)return ans;
        for (int i = 0; i < nums.size(); i++) {
            if (countZeros == 1) {
                if (nums[i] == 0) {
                    ans[i] = prod;
                } else {
                    ans[i] = 0;
                }
            } else {
                ans[i] = prod / nums[i];
            }
        }
        return ans;
    }
};