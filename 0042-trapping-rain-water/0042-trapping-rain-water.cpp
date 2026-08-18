class Solution {
public:
    int trap(vector<int>& arr) {
        int n = arr.size();
        int left = 0;
        int right = n - 1;
        int ans = 0;
        int left_max = INT_MIN;
        int right_max = INT_MIN;
        while (left < right) {
            left_max = max(left_max, arr[left]);
            right_max = max(right_max, arr[right]);

            // deciding factor
            if (left_max < right_max) {
                // left decide
                int trapped_water = left_max - arr[left];
                ans += trapped_water;
                left++;
            } else {
                // right decide
                int trapped_water = right_max - arr[right];
                ans += trapped_water;
                right--;
            }
        }
        return ans;
    }
};