class Solution {
public:
    int findDuplicate(vector<int>& arr) {
        unordered_map<int, int> freq;
        for (int i = 0; i < arr.size(); i++) {
            freq[arr[i]]++;
        }
        for (int i = 0; i < arr.size(); i++) {
            if (freq[arr[i]] >= 2) {
                return arr[i];
            }
        }
        return -1;
    }
};