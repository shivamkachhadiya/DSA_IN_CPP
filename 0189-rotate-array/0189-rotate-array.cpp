class Solution {
public:
    void solve(vector<int>& arr, int start, int end) {
        while (start < end) {
            swap(arr[start], arr[end]);
            start++;
            end--;
        }
    }

    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;

        solve(nums, 0, n - k - 1);
        solve(nums, n - k, n - 1);
        solve(nums, 0, n - 1);
    }
};