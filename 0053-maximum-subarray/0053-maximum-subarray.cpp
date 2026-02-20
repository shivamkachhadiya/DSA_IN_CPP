class Solution {
public:
    int maxSubArray(vector<int>& arr) {
        int currsum=arr[0];
        int best=arr[0];

        for(int i=1;i<arr.size();i++){
            currsum=max(arr[i],currsum+arr[i]);
            best=max(best,currsum);
        }

        return best;

    }
};