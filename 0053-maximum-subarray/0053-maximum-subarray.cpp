class Solution {
public:
    int maxSubArray(vector<int>& arr) {
        int currsum = 0;
        int maxsum = INT_MIN;
        for(int i=0;i<arr.size();i++){
            currsum+=arr[i];
            maxsum=max(currsum,maxsum);
            if(currsum<0){
                currsum=0;
            }
        }
        return maxsum;
    }
};