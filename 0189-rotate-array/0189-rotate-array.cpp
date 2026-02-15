class Solution {
public:
    void rotate(vector<int>& arr, int k) {
        int n = arr.size();
        k = k % n; // handle k > n

        int start = 0;
        int end = n;
        int stop = end - k;
        vector<int> ans;
        if (k > n)
            return;
        for (int i = stop; i < n; i++) {
            ans.push_back(arr[i]);
        }
        for (int i = 0; i < stop; i++) {
            ans.push_back(arr[i]);
        }
        arr = ans;
    }
};