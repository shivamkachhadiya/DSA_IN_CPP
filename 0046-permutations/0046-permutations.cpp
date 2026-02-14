class Solution {
public:
    void solve(vector<int>& arr, vector<vector<int>>& ans,
                              vector<int>& part, vector<bool>& used, int n,
                              int i) {
        if(part.size() == arr.size()) {
            ans.push_back(part);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (used[i])
                continue; // skip already used elements

            part.push_back(arr[i]);
            used[i] = true;

            solve(arr, ans, part,used, n, i);

            part.pop_back();
            used[i] = false;

        }
    }
    vector<vector<int>> permute(vector<int>& nums) {

        vector<vector<int>> ans;
        vector<int> part;
        vector<bool> used(nums.size(), false);

        int n = nums.size();
         solve(nums, ans, part, used, n, 0);
         return ans;
    }
};