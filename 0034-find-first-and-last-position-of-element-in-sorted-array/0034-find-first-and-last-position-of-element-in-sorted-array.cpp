class Solution {
public:
    int lowerbound(vector<int>& arr, int n, int target) {
        int start = 0;
        int end = n - 1;
        int ans1 = -1;
        while (start <= end) {
            int mid = (start + end) / 2;
            if (arr[mid] == target) {
                // kuch to hoga.
                ans1=mid;
                end = mid - 1;
               
            }
            if (arr[mid] < target) {
                start = mid + 1;
            }
            if (arr[mid] > target) {
                end = mid - 1;
            }
        }

        return ans1;
    }
    int upperbound(vector<int>& arr, int n, int target) {
        int start = 0;
        int end = n - 1;
        int ans2 = -1;
        while (start <= end) {
            int mid = (start + end) / 2;
           
            if (arr[mid] == target) {
                // kuch to hoga
                ans2=mid;
                start = mid + 1;
                  
            }
            if (arr[mid] < target) {
                start = mid + 1;
            }if (arr[mid] > target) {
                end = mid - 1;
            }
        }

        return ans2;
    }
    vector<int> searchRange(vector<int>& arr, int target) {
        vector<int> ans;
        int n = arr.size();
        int lb = lowerbound(arr, n, target);
        int ub = upperbound(arr, n, target);
        ans.push_back(lb);
        ans.push_back(ub);
        return ans;
    }
};