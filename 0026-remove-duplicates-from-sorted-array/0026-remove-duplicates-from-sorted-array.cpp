class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
        int n = arr.size();
        if (n == 0) return 0;
        
        int j = 0; // pointer for unique position
        for (int i = 1; i < n; i++) {
            if (arr[i] != arr[j]) {
                j++;
                arr[j] = arr[i];  // place unique element
            }
        }
        return j + 1; // length of unique array
    }
};
