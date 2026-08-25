class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        int start=0;
        int n=arr.size();
        int end=n-1;
        while(start<end){
            int sum=arr[start]+arr[end];
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