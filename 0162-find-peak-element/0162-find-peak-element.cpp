class Solution {
public:
    int findPeakElement(vector<int>& arr) {
        int n = arr.size();

        int ans = -1;
        int start = 0;
        int end = n - 1;
        while (start <= end) {
            int mid = (start + end) / 2;
            if (n == 1)
                return 0;
            if (mid == 0) {
                if (arr[0] > arr[1])
                    return 0;
                else
                    return 1;
            }

             if (mid == n - 1) {
                if (arr[n - 1] > arr[n - 2]) return n - 1;
                else return n - 2;
            }

            if (arr[mid] >= arr[mid - 1] && arr[mid] >= arr[mid + 1]) {
                return mid;
            }
            else if (arr[mid - 1] <= arr[mid] && arr[mid] <= arr[mid + 1]) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return -1;
    }
};