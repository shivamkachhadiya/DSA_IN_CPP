class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {
        int n = arr.size();
        set<vector<int>> st;   // ✅ unique triplets
        sort(arr.begin(), arr.end());

        for (int i = 0; i < n; i++) {
            int j = i + 1;
            int k = n - 1;
            while (j < k) {
                int sum = arr[i] + arr[j] + arr[k];
                if (sum == 0) {
                    st.insert({arr[i], arr[j], arr[k]}); // ✅ duplicates auto removed
                    j++;
                    k--;
                } else if (sum > 0) {
                    k--;
                } else {
                    j++;
                }
            }
        }

        // convert set to vector
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};
