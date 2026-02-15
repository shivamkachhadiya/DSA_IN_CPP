class Solution {
public:
    int i = 0;
    int removeDuplicates(vector<int>& nums) {
       
        for (int j=1; j < nums.size(); j++) {
            if (nums[i] != nums[j]) {
                i++;
                nums[i] = nums[j];
            }
        }

        return i + 1;
    }
};