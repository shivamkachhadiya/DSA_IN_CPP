class Solution {
public:
    int minSubArrayLen(int target, vector<int>& arr) {
        int n = arr.size();
        int left = 0, right = 0;
        int currsum=0;
        int final_ans=INT_MAX;
        while (right < n) {
            currsum += arr[right];
            while(currsum>=target){
                final_ans=min(final_ans,right-left+1);
                currsum-=arr[left];
                left++;
            }
            right++;
        }
        return final_ans==INT_MAX?0:final_ans;
    }
};