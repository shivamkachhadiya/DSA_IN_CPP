class Solution {
public:
    int solve(vector<int>&arr,int n,int i,int minPrice){
        if(i>=n){
            return 0;
        }
        int profitToday=arr[i]-minPrice;
        minPrice=min(minPrice,arr[i]);

        int futureProfit=solve(arr,n,i+1,minPrice);

        return max(profitToday,futureProfit);

    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        return solve(prices,n,0,prices[0]);
    }
};