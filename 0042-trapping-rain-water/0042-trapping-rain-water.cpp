class Solution {
public:
    int trap(vector<int>& arr) {
        int left=0;
        int n=arr.size();
        int right=n-1;
        int maxAns=0;
        int leftMax=0;
        int rightMax=0;
        while(left<=right){
            leftMax=max(leftMax,arr[left]);
            rightMax=max(rightMax,arr[right]);

            if(leftMax<=rightMax){
                int trap=leftMax-arr[left];
                maxAns+=trap;
                left++;
            }else{
                //rightMax decide
                int trap=rightMax-arr[right];
                maxAns+=trap;
                right--;
            }
        }
        return maxAns;
    }
};