class Solution {
public:
    int maxArea(vector<int>& arr) {
        int start=0;
        int n=arr.size();
        int end=n-1;
        int ans=0;
        while(start<end){
            int leftH=arr[start];
            int rightH=arr[end];

            int finalH=min(leftH,rightH);
            int distance=end-start;

            ans=max(ans,finalH*distance);

            if(leftH<rightH){
                start++;
            }else{
                end--;
            }

        }
        return ans;
    }
};