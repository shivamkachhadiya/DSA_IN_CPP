class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans=0;
        int i=0;
        int j=1;
        int n=nums.size();
        while(i<n&&j<=n-1){
            if(nums[i]==nums[j]){
                ans=nums[i];
                break;
            }else{
                i++;
                j++;
            }
        }
        return ans;
        
    }
};