class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double maxi=INT_MIN;
        int n=nums.size();
        double currSum=0;
        int left=0;
        int right=0;
        for(;right<k;right++){
            currSum+=nums[right];
        }
        double ans=currSum/k;
        maxi=max(maxi,ans);
        while(right<n){
            currSum-=nums[left];
            left++;
           
            currSum+=nums[right];
            ans=currSum/k;
            maxi=max(maxi,ans);
             right++;
        }
        return maxi;
    }
};