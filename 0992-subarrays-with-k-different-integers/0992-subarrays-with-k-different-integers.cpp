class Solution {
public:
    int solve(vector<int>& arr, int k) {
        int count=0;
        int n = arr.size();
        unordered_map<int, int> map;
        int left = 0;
        for (int right = 0; right < n; right++) {
            map[arr[right]]++;
            while(map.size()>k){
                map[arr[left]]--;
                if(map[arr[left]]==0)map.erase(arr[left]);
                left++;
            }
            count += right - left + 1;
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& arr, int k) {
        return solve(arr,k)-solve(arr,k-1);
    }
};