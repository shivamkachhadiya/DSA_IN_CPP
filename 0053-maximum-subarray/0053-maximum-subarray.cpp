class Solution {
public:
    int maxSubArray(vector<int>& arr) {
        int n=arr.size();
        if(n==1)return arr[0];
        int maxSum=arr[0];
        int currSum=0;

        for(auto &x:arr){
            currSum+=x;
            maxSum=max(currSum,maxSum);
            if(currSum<0){
                currSum=0;
            }
        }
        return maxSum;

    }
};