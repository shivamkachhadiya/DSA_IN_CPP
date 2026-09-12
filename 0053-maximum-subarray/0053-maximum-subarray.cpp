class Solution {
public:
    int maxSubArray(vector<int>& arr) {
        int currSum=0;
        int maxSum=arr[0];
        for(int i=0;i<arr.size();i++){
            currSum+=arr[i];
            maxSum=max(maxSum,currSum);
            if(currSum<0){
                currSum=0;
            }
        }
        return maxSum;
    }
};