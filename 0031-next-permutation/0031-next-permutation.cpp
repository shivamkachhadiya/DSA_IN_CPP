class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int pivot;
        int pivotindex = -1;
        int n = nums.size();
        for (int i = n - 1; i > 0; i--) {
            if (nums[i] > nums[i - 1]) {
                pivotindex = i - 1;
                break;
            }
        }
        if (pivotindex == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        for (int i = n - 1; i > pivotindex; i--) {
            if (nums[i] > nums[pivotindex]) {
                swap(nums[i], nums[pivotindex]);
                break;
            }
        }
        int start = pivotindex + 1;
        int end = n - 1;
        int mid = (start + end) / 2;
        while (start <= end) {
            swap(nums[start], nums[end]);
            start++;
            end--;
        }
    }
};