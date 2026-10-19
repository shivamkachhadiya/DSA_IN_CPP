
class Solution {
public:
    int findMin(vector<int>& arr) {
        int start = 0;
        int end = arr.size() - 1;

        while (start < end) {
            int mid = start + (end - start) / 2;

            if (arr[mid] > arr[end]) {
                // Minimum right half mein hai
                start = mid + 1;
            } else {
                // Minimum mid ya left half mein hai
                end = mid;
            }
        }

        return arr[start];
    }
};
