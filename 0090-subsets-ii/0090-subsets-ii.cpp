class Solution {
public:
    void solve(vector<int>& arr, int i, int n,
               vector<int>& part,
               vector<vector<int>>& ans) {

        if (i == n) {
            ans.push_back(part);
            return;
        }

        // include current element
        part.push_back(arr[i]);
        solve(arr, i + 1, n, part, ans);
        part.pop_back();

        // exclude current element
        // skip all duplicates
        while (i + 1 < n && arr[i] == arr[i + 1]) {
            i++;
        }
        solve(arr, i + 1, n, part, ans);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> part;
        solve(nums, 0, nums.size(), part, ans);
        return ans;
    }
};
