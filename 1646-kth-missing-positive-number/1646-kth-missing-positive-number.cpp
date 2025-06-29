class Solution {
public:
    // You can keep your binary search if you want to reuse it, but it's not needed here.
    bool binarysearch(vector<int>& arr, int n, int target){
        int low = 0;
        int high = n - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (arr[mid] == target) return true;
            else if (arr[mid] > target) high = mid - 1;
            else low = mid + 1;
        }
        return false;
    }

    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int count = 0;      // count of missing numbers
        int num = 1;        // current number to check

        while (true) {
            if (!binarysearch(arr, n, num)) {
                count++;
                if (count == k) return num;
            }
            num++;
        }
    }
};
