class Solution {
public:
    int minSubArrayLen(int target, vector<int>& arr) {
        int n=arr.size();
        int ans=INT_MAX;
        int sum=0;
        int left=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            while(sum>=target){
                ans=min(ans,i-left+1);
                sum-=arr[left];
                left++;
            }

        }
        return ans==INT_MAX?0:ans;
    }
};