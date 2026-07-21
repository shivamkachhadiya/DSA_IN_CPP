class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int start=0;
        int end=n-1;
        int ans=0;
        int left_max=0;
        int right_max=0;
        while(start<end){
            left_max=max(left_max,height[start]);
            right_max=max(right_max,height[end]);

            if(left_max<right_max){
                //left is decide
                ans+=left_max-height[start];
                start++;
            }else{
                //right is decide
                ans+=right_max-height[end];
                end--;
            }
        }
        return ans;
    }
};