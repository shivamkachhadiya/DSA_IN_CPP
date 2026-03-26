class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int n=arr.size();
        int mini=arr[0];
        int profit=0;

        for(int i=1;i<n;i++){
            int diff=arr[i]-mini;
            profit=max(diff,profit);
            mini=min(mini,arr[i]);
        }
        return profit;
    }
};