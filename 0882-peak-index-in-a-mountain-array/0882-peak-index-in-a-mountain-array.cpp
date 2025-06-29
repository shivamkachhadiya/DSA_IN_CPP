class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int start = 1, end = n - 2;
        while (start <= end) {
            int mid = (start + end) / 2;
            if (arr[mid - 1] < arr[mid] && arr[mid + 1] < arr[mid])
                return mid;
            else if (arr[mid - 1] < arr[mid]) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return -1;
    }
};