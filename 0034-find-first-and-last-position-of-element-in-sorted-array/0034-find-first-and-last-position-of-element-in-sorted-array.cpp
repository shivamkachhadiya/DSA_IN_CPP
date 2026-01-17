class Solution {
public:
    int solve1(vector<int>& arr, int target, int n) {
        int start=0,end=n-1;
        int ans=-1;
        while (start <= end) {
            int mid = (start + end) / 2;
            if (arr[mid] == target) {
                ans = mid;
                end = mid - 1;
            } else if (arr[mid] > target) {
                end=mid-1;
            } else {
               start=mid+1;
            }
        }
        return ans;
    }

    int solve2(vector<int>& arr, int target, int n) {
        int start=0,end=n-1;
        int ans=-1;
        while (start <= end) {
            int mid = (start + end) / 2;
            if (arr[mid] == target) {
                ans = mid;
                start=mid+1;
            } else if (arr[mid] > target) {
                end=mid-1;
            } else {
                start=mid+1;
            }
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& arr, int target) {
        int n = arr.size();
        int fistoccur = solve1(arr, target, n);
        int secondocuur = solve2(arr, target, n);
        vector<int>ans;
        ans.push_back(fistoccur);
        ans.push_back(secondocuur);
        return ans;
    }
};