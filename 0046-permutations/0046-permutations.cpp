class Solution {
public:
    void permute(vector<int>& ds, vector<int>& nums, vector<vector<int>>& ans, vector<int>& freq) {
        if (ds.size() == nums.size()) {
            ans.push_back(ds);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (!freq[i]) {
                ds.push_back(nums[i]);
                freq[i] = 1;

                permute(ds, nums, ans, freq);

                freq[i] = 0;
                ds.pop_back();
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        vector<int> freq(nums.size(), 0); // ✅ VLA replaced with vector
        permute(ds, nums, ans, freq);
        return ans;
    }
};
