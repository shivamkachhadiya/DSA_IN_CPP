class Solution {
public:
    int search(vector<int>& arr, int target) {
        int start = 0;
        int end = arr.size() - 1;

        while (start <= end) {
            int mid = (start + end) / 2;

            if (arr[mid] == target) return mid;

            // Left part sorted
            if (arr[start] <= arr[mid]) {
                if (arr[start] <= target && target < arr[mid]) {
                    end = mid - 1;   // ✅ move left
                } else {
                    start = mid + 1; // ✅ move right
                }
            }
            // Right part sorted
            else {
                if (arr[mid] < target && target <= arr[end]) {
                    start = mid + 1; // ✅ move right
                } else {
                    end = mid - 1;   // ✅ move left
                }
            }
        }
        return -1;
    }
};
