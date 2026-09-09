class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
        unordered_map<int,int> mp;
        mp[0] = 1; // empty prefix
        int sum = 0, count = 0;

        for(int x : arr){
            sum += x;
            if(mp.find(sum - k) != mp.end()){
                count += mp[sum - k];
            }
            mp[sum]++;
        }
        return count;
    }
};
