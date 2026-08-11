class Solution {
public:
    int findMin(vector<int>& arr) {
        int n = arr.size();
        int start = 0, end = n - 1;

        while (start < end) {
            int mid = start + (end - start) / 2;

            // If mid element > end element, min lies in right half
            if (arr[mid] > arr[end]) {
                start = mid + 1;
            } 
            // Else min lies in left half (including mid)
            else {
                end = mid;
            }
        }
        return arr[start];
    }
};
