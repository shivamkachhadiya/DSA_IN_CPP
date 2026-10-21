class Solution {
public:
    vector<vector<int>> ans;
    void solve(vector<int>& arr, int target, vector<int>& part, int i,
               int currSum) {
        if (i == arr.size()) {
            if (currSum == target) {
                ans.push_back(part);
                return;
            }
            return;
        }

        if (currSum > target)
            return;
        if (currSum == target) {
            ans.push_back(part);
            return;
        }
        part.push_back(arr[i]);
        solve(arr, target, part, i, currSum + arr[i]);
        part.pop_back();
        solve(arr, target, part, i + 1, currSum);
    }
    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> part;
        solve(arr, target, part, 0, 0);
        return ans;
    }
};