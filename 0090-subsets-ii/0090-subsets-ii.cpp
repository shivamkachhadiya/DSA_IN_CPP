class Solution {
public:
    void solve(vector<int>& nums, vector<vector<int>>& ans, vector<int>& part, int i) {
        if (i == nums.size()) {
            ans.push_back(part);
            return;
        }
        // Include nums[i]
        part.push_back(nums[i]);
        solve(nums, ans, part, i + 1);
        part.pop_back();
        // Exclude nums[i]
        solve(nums, ans, part, i + 1);
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> part;
        sort(nums.begin(), nums.end());  // Sort to handle duplicates
        solve(nums, ans, part, 0);
        
        // Remove duplicate subsets
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        
        return ans;
    }
};