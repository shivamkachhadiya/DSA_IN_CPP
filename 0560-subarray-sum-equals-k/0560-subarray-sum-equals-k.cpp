class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> prefix(n);
        prefix[0] = arr[0];
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + arr[i];
        }

        int count = 0;
        unordered_map<int, int> map;
        for (int j = 0; j < n; j++) {
            if (prefix[j] == k)
                count++;
            int val = prefix[j] - k;
            if (map.find(val) != map.end()) {
                count += map[val];
            }
            map[prefix[j]]++;
        }
        return count;
    }
};