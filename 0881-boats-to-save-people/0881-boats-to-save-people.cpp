class Solution {
public:
    int numRescueBoats(vector<int>& arr, int limit) {
        sort(arr.begin(), arr.end());
        int left = 0, right = arr.size() - 1;
        int boats = 0;
        
        while (left <= right) {
            if (arr[left] + arr[right] <= limit) {
                left++;   // lightest + heaviest together
            }
            right--;      // heaviest always goes
            boats++;
        }
        
        return boats;
    }
};
