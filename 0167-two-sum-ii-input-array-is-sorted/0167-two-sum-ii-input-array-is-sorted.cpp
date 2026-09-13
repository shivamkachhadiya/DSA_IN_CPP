class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
       int left=0;
       int right=arr.size();
       int currSum=0;
       int right=n-1;
       while(left<=right){
           int sum=arr[left]+arr[right];
           if(sum==target){
            return {start+1,end+1};
           }
           if(sum>target){
            end--;
           }
           if(sum<target){
            start++;
           }
       }
       return {};        
    }
};