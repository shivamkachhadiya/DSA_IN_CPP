class Solution {
public:
    int longestOnes(vector<int>& arr, int k) {
        int n=arr.size();
        int left=0;
        int count=0;
        int r=0;

        int maxlen=0;
        for(;r<n;r++){
            if(arr[r]==0){
                count++;
            }
            while(count>k){
                if(arr[left]==0)
                    count--;
                left++;
            }
            maxlen=max(maxlen,r-left+1);
        }
        return maxlen;
    }
};