class Solution {
public:
    vector<vector<int>> solve(vector<int>& arr, int n, vector<int>& part,
                              vector<vector<int>>& ans,
                              int i, bool prevTaken) {

        if (i == n) {
            ans.push_back(part);
            return ans;
        }

        // 🔴 NOT TAKE
        solve(arr, n, part, ans, i + 1, false);

        // 🔴 TAKE (only if allowed)
        if (i > 0 && arr[i] == arr[i - 1] && !prevTaken)
            return ans;

        part.push_back(arr[i]);
        solve(arr, n, part, ans, i + 1, true);
        part.pop_back();

        return ans;
    }

    vector<vector<int>> subsetsWithDup(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        vector<vector<int>> ans;
        vector<int> part;
        solve(arr, arr.size(), part, ans, 0, false);
        return ans;
    }
};
