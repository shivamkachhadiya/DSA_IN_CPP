class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;

        for (int x : nums) {
            // If even, impossible
            if ((x & 1) == 0) {
                ans.push_back(-1);
                continue;
            }

            // Count trailing 1s
            int k = 0;
            int temp = x;
            while (temp & 1) {
                k++;
                temp >>= 1;
            }

            // Minimum valid ans
            ans.push_back(x - (1 << (k - 1)));
        }

        return ans;
    }
};
