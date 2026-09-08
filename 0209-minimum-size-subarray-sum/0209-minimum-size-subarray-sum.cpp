class Solution {
public:
    int minSubArrayLen(int target, vector<int>& arr) {
        int n=arr.size();
        int left=0;
        int right=0;
                int mini = INT_MAX;
        int sum=0;
        while(right<n){
            sum+=arr[right];
            while(sum >= target) {
                mini = min(mini, right - left + 1);
                sum -= arr[left];
                left++;
            }

            right++;
        }
                return mini == INT_MAX ? 0 : mini;
    }
};