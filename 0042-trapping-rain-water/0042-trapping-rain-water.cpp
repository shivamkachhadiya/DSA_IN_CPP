class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int left=0;
        int right=n-1;
        int left_max=INT_MIN;
        int right_max=INT_MIN;
        int ans=0;
        while(left<right){
            left_max=max(left_max,height[left]);
            right_max=max(right_max,height[right]);
            if(left_max<right_max){
                int trap_water=left_max-height[left];
                ans+=trap_water;
                left++;
            }else{
                int trap_water=right_max-height[right];
                ans+=trap_water;
                right--;
            }
        }
        return ans;
    }
};