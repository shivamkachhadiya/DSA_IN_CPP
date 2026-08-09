class Solution {
public:
    int trap(vector<int>& arr) {
        int n=arr.size();
        int ans=0;
        int left=0;
        int right=n-1;
        int leftmax=0;
        int rightmax=0;
        while(left<right){
            leftmax=max(leftmax,arr[left]);
            rightmax=max(rightmax,arr[right]);
            if(leftmax<rightmax){
                ans+=leftmax-arr[left];
                left++;
            }else{
                ans+=rightmax-arr[right];
                right--;
            }
        }
        return ans;
    }
};