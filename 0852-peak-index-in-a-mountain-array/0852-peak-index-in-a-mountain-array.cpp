class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
            int start = 1, end = arr.size() - 2; // safe boundaries

        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]) {
                return mid;
            } else if (arr[mid] > arr[mid + 1]) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return -1;
    }
};