class Solution {
public:
    static int minOperations(string& s) {
        const int n=s.size();
        if(n==1) return 0;
        if(n==2) return 0-(s[0]>s[1]);
        char mx='a', mn='z';
        bool is_sorted=s[0]<=s[1];
        for(int i=1; i<n-1; i++){
            is_sorted&=(s[i]<=s[i+1]);
            mn=min(mn, s[i]);
            mx=max(mx, s[i]);
        }
        if (is_sorted) return 0;
        if ((s[0]<=mn && s[0]<=s.back()) || (s.back()>=mx && s.back()>=s[0])) {
            return 1;
        }
        if (mx<s[0] && mn>s.back()) return 3;
        return 2;
    }
};