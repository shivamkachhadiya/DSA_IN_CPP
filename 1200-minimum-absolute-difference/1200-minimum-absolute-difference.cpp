class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        
        int minDiff = INT_MAX;
        int n = arr.size();
        
        // Step 1: find minimum difference
        for (int i = 1; i < n; i++) {
            minDiff = min(minDiff, arr[i] - arr[i - 1]);
        }
        
        // Step 2: collect pairs with min difference
        vector<vector<int>> result;
        for (int i = 1; i < n; i++) {
            if (arr[i] - arr[i - 1] == minDiff) {
                result.push_back({arr[i - 1], arr[i]});
            }
        }
        
        return result;
    }
};
