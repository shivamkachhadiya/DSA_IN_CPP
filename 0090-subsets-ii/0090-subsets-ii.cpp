class Solution {
public:
    vector<vector<int>> ans;
     set<vector<int>> st;
    void solve(vector<int>& arr, int n, vector<int>& part, int i) {
        if (i >= n) {
           st.insert(part); 
            return;
        }
        part.push_back(arr[i]);
        solve(arr, n, part, i + 1);
        part.pop_back();
        solve(arr, n, part, i + 1);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int n = arr.size();
        vector<int> part;
        solve(arr, n, part, 0);
        return vector<vector<int>>(st.begin(),st.end());
    }
};