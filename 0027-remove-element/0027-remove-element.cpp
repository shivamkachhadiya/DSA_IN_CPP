class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;  // Pointer to place next non-val element
        for (int i = 0; i < (int)nums.size(); i++) {
            if (nums[i] != val) {
                nums[k] = nums[i];
                k++;
            }
        }
        return k;
    }
};
