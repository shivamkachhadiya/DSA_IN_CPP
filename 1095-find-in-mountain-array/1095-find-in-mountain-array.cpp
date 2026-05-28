/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
   public:
    int leftSearch(MountainArray& arr, int start, int end, int target) {
        while (start <= end) {
            int mid = (start + end) / 2;
            int mid_val = arr.get(mid);

            if (mid_val == target) return mid;

            if (mid_val < target) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return -1;
    }
    int rightSearch(MountainArray& arr, int start, int end, int target) {
        while (start <= end) {
            int mid = (start + end) / 2;
            int mid_val = arr.get(mid);

            if (mid_val == target) return mid;

            if (mid_val < target) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return -1;
    }

   public:
    int findInMountainArray(int target, MountainArray& arr) {
        int left = 0;
        int n = arr.length();
        int right = n - 1;

        while (left < right) {
            int mid = (left + right) / 2;
            int midValue = arr.get(mid);
            int nextValue = arr.get(mid + 1);

            if (midValue < nextValue) {
                // increseing part
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        int peakIndex = left;  // right

        // Step 2: Search in the left half (0 -> peakIndex)

        int result = leftSearch(arr, 0, peakIndex, target);
        if (result != -1) {
            return result;
        }

        int result_right = rightSearch(arr, peakIndex + 1, n - 1, target);
        if (result_right != -1) {
            return result_right;
        }

        return -1;
    }
};