class Solution {
public:
    void sortColors(vector<int>& nums) {
        int count0 = 0, count1 = 0, count2 = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                count0++;
            } else if (nums[i] == 1) {
                count1++;
            } else {
                count2++;
            }
        }
        int i = 0;
        vector<int> tmp;
        while (i < count0) {
            tmp.push_back(0);
            i++;
        }
        while (i < (count1 + count0)) {
            tmp.push_back(1);
            i++;
        }
        while (i < (count2 + count1 + count0)) {
            tmp.push_back(2);
            i++;
        }
        nums = tmp;
    }
};