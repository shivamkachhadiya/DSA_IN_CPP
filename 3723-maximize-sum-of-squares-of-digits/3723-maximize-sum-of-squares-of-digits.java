class Solution {
    public String maxSumOfSquares(int num, int sum) {
        if (sum > 9 * num)
            return "";

        int q = sum / 9;
        int r = sum % 9;

        StringBuilder ans = new StringBuilder();

        for (int i = 0; i < q; i++)
            ans.append('9');

        if (r > 0)
            ans.append(r);

        while (ans.length() < num)
            ans.append('0');

        return ans.toString();
    }
}