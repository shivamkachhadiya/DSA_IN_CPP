class Solution {
    boolean solveDp(String str, String pattern, int i, int j, int[][] dp) {
        if (i < 0 && j < 0)
            return true;
        if (i >= 0 && j < 0)
            return false;

        if (i < 0 && j >= 0) {
            for (int k = 0; k <= j; k++) {
                if (pattern.charAt(k) != '*')
                    return false;
            }
            return true;
        }

        if (dp[i][j] != -1)
            return dp[i][j] == 1;
        boolean ans;

        if (str.charAt(i) == pattern.charAt(j) || pattern.charAt(j) == '?') {
            ans = solveDp(str, pattern, i - 1, j - 1, dp);

        }else if(pattern.charAt(j)=='*'){
            ans=solveDp(str,pattern,i,j-1,dp) || solveDp(str,pattern,i-1,j,dp);
        }else{
            return false;
        }

        dp[i][j]=ans?1:0;

        return ans;

    }

    public boolean isMatch(String s, String p) {

        int n = s.length();
        int m = p.length();

        int[][] dp = new int[n][m];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                dp[i][j] = -1;
            }
        }

        return solveDp(s, p, n - 1, m - 1, dp);
    }
}