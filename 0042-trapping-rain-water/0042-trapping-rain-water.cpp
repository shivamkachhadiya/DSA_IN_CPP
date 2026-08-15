class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int ans=0;
        int left_max=0;
        int right_max=0;
        int start=0;
        int end=n-1;
        while(start<end){
            left_max=max(left_max,height[start]);
            right_max=max(right_max,height[end]);
            if(left_max<right_max){
                int remain_out=left_max-height[start];
                ans+=remain_out;
                start++;
            }else{
                int remain_out=right_max-height[end];
                ans+=remain_out;
                end--;
            }
        }
        return ans;
    }
};