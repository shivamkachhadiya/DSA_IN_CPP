// User function Template for C++
#define MOD 1000000007
#include <vector>

class Solution {
  public:
  
long long int solveMem(int n, vector<long long int> &dp)
{
    if (n == 1)
        return 0;
    if (n == 2)
        return 1;
    if (dp[n] != -1)
        return dp[n];
    // dp[n] = (((n - 1) % MOD) * ((solveMem(n - 1, dp) * MOD) + (solveMem(n - 1, dp) % MOD)) % MOD);
        dp[n] = ((n - 1) % MOD * ( (solveMem(n - 1, dp) + solveMem(n - 2, dp)) % MOD )) % MOD;

    return dp[n];
}
    int countDer(int n) {
        
        vector<long long int> dp(n + 1, -1);
        return solveMem(n, dp);
    }
};