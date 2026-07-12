class Solution {
public:
    int leftBound(vector<int>& arr, int target) {
        int start = 0;
        int end = arr.size() - 1;
        int ans=-1;
        while (start <= end) {
            int mid = (start + end) / 2;
            if (arr[mid] == target) {
                ans=mid;
                end = mid - 1;
            }
            else if (arr[mid] < target) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return ans;
    }
    int rightBound(vector<int>& arr, int target) {
        int start = 0;
        int end = arr.size() - 1;
        int ans1=-1;
        while (start <= end) {
            int mid = (start + end) / 2;
            if (arr[mid] == target) {
                ans1=mid;
                start = mid + 1;
            }
            else if (arr[mid] < target) {
                start=mid+1;
            } else {
                end = mid - 1;
            }
        }
        return ans1;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int leftAns=leftBound(nums,target);
        int rightAns=rightBound(nums,target);
        return {leftAns,rightAns};
        
    }
};