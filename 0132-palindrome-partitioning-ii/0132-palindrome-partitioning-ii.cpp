class Solution {
public:
    bool ispalindrome(string& temp) {
        int left = 0, right = temp.size() - 1;
        while (left < right) {
            if (temp[left] != temp[right])
                return false;
            left++;
            right--;
        }
        return true;
    }

    int solve(string& s, int n, int i) {
        if (i == n)
            return 0;
        string temp = "";
        int min_cost = INT_MAX;
        for (int j = i; j < n; j++) {
            temp += s[j];
            if (ispalindrome(temp)) {
                int cost = 1 + solve(s,n,j + 1);
                min_cost = min(min_cost, cost);
            }
        }
        return min_cost;
    }
        int solveMEM(string& s, int n, int i, vector<int>& dp) {
        if (i == n)
            return 0;
         if (dp[i] != -1)   //already computed
            return dp[i];
        string temp = "";
        int min_cost = INT_MAX;
        for (int j = i; j < n; j++) {
            temp += s[j];
            if (ispalindrome(temp)) {
                int cost = 1 + solveMEM(s,n,j + 1,dp);
                min_cost = min(min_cost, cost);
            }
        }
        return dp[i] = min_cost; 
    }
    int minCut(string s) {
        int n = s.size();
                vector<int> dp(n, -1);
        //solve recursion
        //return solve(s, n, 0)-1;
        //solve memoization
        return solveMEM(s, n, 0,dp)-1;
    }
};