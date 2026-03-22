class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int> result(n);
        int left = 0;
        
        // Fill elements smaller than pivot
        for (int x : nums) {
            if (x < pivot) {
                result[left++] = x;
            }
        }
        
        // Fill elements equal to pivot
        for (int x : nums) {
            if (x == pivot) {
                result[left++] = x;
            }
        }
        
        //  Fill elements greater than pivot
        for (int x : nums) {
            if (x > pivot) {
                result[left++] = x;
            }
        }
        
        return result;
    }
};