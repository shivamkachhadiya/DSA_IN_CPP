class Solution {
public:
    int findFirst(vector<int>& arr, int target) {
        int start = 0, end = arr.size() - 1, index = -1;
        while (start <= end) {
            int mid = (start + end) / 2;
            if (arr[mid] == target) {
                index = mid;
                end = mid - 1; // go left
            } else if (arr[mid] < target) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return index;
    }

    int findLast(vector<int>& arr, int target) {
        int start = 0, end = arr.size() - 1, index = -1;
        while (start <= end) {
            int mid = (start + end) / 2;
            if (arr[mid] == target) {
                index = mid;
                start = mid + 1; // go right
            } else if (arr[mid] < target) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return index;
    }

    vector<int> searchRange(vector<int>& arr, int target) {
        int first = findFirst(arr, target);
        int last = findLast(arr, target);
        return {first, last};
    }
};
