class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        int sum=0;
        int left=0;
        int right=arr.size()-1;
        while(left<right){
            if(arr[left]+arr[right]==target)return {left+1,right+1};
            if(arr[left]+arr[right]<target){
                //right bada hei
                left++;
            }
            if(arr[left]+arr[right]>target){
                right--;
            }
        }
        return {};
    }
};