class Solution {
public:
    int findMin(vector<int>& arr) {
        int n = arr.size();
        int ans = INT_MAX;
        int low = 0, high = n - 1;
       
        
        while (low <=high) {
            int mid = (high + low) / 2;
            if(arr[low]<=arr[high]){
                ans=min(ans,arr[low]);
                break;
            }
           
            if (arr[low] <= arr[mid]) {
                // left half sorted
                ans = min(ans, arr[low]);
                low = mid + 1;

            } else {
                // right half sorted
                ans = min(ans, arr[mid]);
                high = mid - 1;
            }
        }
        return ans;
    }
};