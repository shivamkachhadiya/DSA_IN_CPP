class Solution {
public:
    bool isPossible(vector<int>& arr, int target, int currentlyEating) {
        long long totalTimeTaken = 0;

        for (int i = 0; i < arr.size(); i++) {
            int currTime = ceil((double)arr[i] / currentlyEating);
            totalTimeTaken += currTime;
        }

        return totalTimeTaken <= target;
    }

    int minEatingSpeed(vector<int>& arr, int h) {
        int n = arr.size();
        int end = *max_element(arr.begin(), arr.end());
        int ans = end;

        int start=1;
        while(start<=end){
            int mid=(start+end)/2;
            if(isPossible(arr,h,mid)){
                ans=mid;
                end=mid-1;
            }else{
                start=mid+1;
            }
        }

        return ans;
    }
};