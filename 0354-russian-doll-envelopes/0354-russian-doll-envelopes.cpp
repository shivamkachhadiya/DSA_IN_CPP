class Solution {
public:
    int lengthOfLIS(int n, vector<int>& a) {
        if (n == 0)
            return 0;

        vector<int> ans;
        ans.push_back(a[0]);

        for (int i = 1; i < n; i++) {
            if (a[i] > ans.back()) {
                // If current element is greater than last element in ans,
                // append it
                ans.push_back(a[i]);
            } else {
                // Find index of the smallest element >= a[i] and replace it
                int index =
                    lower_bound(ans.begin(), ans.end(), a[i]) - ans.begin();
                ans[index] = a[i];
            }
        }
        return ans.size(); // length of LIS
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [](auto& a, auto& b) {
            if (a[0] == b[0])
                return a[1] > b[1]; // width same -> sort by height desc
            return a[0] < b[0];
        });
        vector<int> heights;
        for (auto& env : envelopes) {
            heights.push_back(env[1]);
        }
        int n=heights.size();
        return lengthOfLIS(n,heights);
    }
};