class Solution {
public:
    int solve(int n,int i){
        if(i==n)return 1;
        if(i>n)return 0;
        return solve(n,i+1)+solve(n,i+2);
    }
    int climbStairs(int n) {
        return solve(n,0);
    }
};