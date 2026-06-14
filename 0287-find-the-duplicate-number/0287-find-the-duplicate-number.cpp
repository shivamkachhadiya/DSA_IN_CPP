class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        set<int> st;
        for (int i = 0; i < nums.size(); i++) {
            if (st.find(nums[i]) != st.end()) {
                // mil gaya
                return nums[i];
            }
            st.insert(nums[i]);
        }
        return -1;
    }
};