class Solution {
public:
    int solveMem(int curr, int prev, vector<int>& arr, int n,
                 vector<vector<int>>& dp) {

        // Base case
        if (curr == n)
            return 0;

        // Memoization check
        if (dp[curr][prev + 1] != -1)
            return dp[curr][prev + 1];

        // Not take
        int len = solveMem(curr + 1, prev, arr, n, dp);

        // Take
        if (prev == -1 || arr[curr] > arr[prev]) {
            len = max(len, 1 + solveMem(curr + 1, curr, arr, n, dp));
        }

        return dp[curr][prev + 1] = len;
    }

    int solveTab(vector<int>&arr,int n){
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));

        for(int curr=n-1;curr>=0;curr--){
            for(int prev=curr-1;prev>=-1;prev--){
                int take=0;
                if(prev==-1 || arr[curr]>arr[prev]){
                    take=1+dp[curr+1][curr+1];
                }
                int notTake=0+dp[curr+1][prev+1];

                dp[curr][prev+1]=max(take,notTake);
            }
        }
        return dp[0][0];
    }
    int lengthOfLIS(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return solveTab(arr,n);
        //return solveMem(0, -1, arr, n, dp);
    }
};
