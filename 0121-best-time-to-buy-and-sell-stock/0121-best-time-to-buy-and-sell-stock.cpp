class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int mini=arr[0];
        int profit=0;
        int n=arr.size();

        for(int i=0;i<n;i++){
            int diff=arr[i]-mini;
            profit=max(profit,diff);
            mini=min(mini,arr[i]);
        }
        return profit;
    }
};