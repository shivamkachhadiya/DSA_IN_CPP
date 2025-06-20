class Solution {
public:
    void printsubset(vector<int>& arr, vector<int>& subset, vector<vector<int>>& ans, int i) {
        if (i == arr.size()) {
            ans.push_back(subset);  // base case: push current subset
            return;
        }

        // Include the current element
        subset.push_back(arr[i]);
        printsubset(arr, subset, ans, i + 1);

        // Exclude the current element (backtrack)
        subset.pop_back();
        printsubset(arr, subset, ans, i + 1);
    }

    vector<vector<int>> subsets(vector<int>& arr) {
        vector<vector<int>> ans;
        vector<int> subset;
        printsubset(arr, subset, ans, 0);
        return ans;
    }
};
