class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        vector<int> ans;
        for (int i = 0; i < arr.size(); i++) {
            int complement = target - arr[i];
            auto it = find(arr.begin()+i+1, arr.end(), complement);
            if (it != arr.end()) {
                int index = it - arr.begin();
                return {i, index};
            }
        }
        return {};
    }
};