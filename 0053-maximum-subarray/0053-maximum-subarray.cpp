class Solution {
public:
    int maxSubArray(vector<int>& arr) {
        int n=arr.size();
        int maxsum=INT_MIN;
        int currsum=0;
        for(int i=0;i<n;i++){
            currsum=currsum+arr[i];
            maxsum=max(currsum,maxsum);
            if(currsum<0){
                
                currsum=0;                
            }
        }
        return maxsum;

    }
};