class Solution {
public:
    vector<int> productExceptSelf(vector<int>& arr) {
        int n = arr.size();
        vector<int> pref(n);
        vector<int> suff(n);
        vector<int> ans(n);

        pref[0] = 1;
        for (int i = 1; i < n; i++) {
            pref[i] = pref[i - 1] * arr[i - 1];
        }

        suff[n - 1] = 1;
        for (int i = n - 2; i >= 0; i--) {
            suff[i] = suff[i + 1] * arr[i + 1];
        }

        for (int i = 0; i < n; i++) {
            ans[i]=pref[i] * suff[i];
        }

        return ans;
    }
};