class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_map<char, int> map;   
        int l = 0, r = 0;
        int ans = 0;
        while (r < n) {
            if (map.find(s[r]) != map.end()&& map[s[r]] >= l) {
                l=map[s[r]]+1;
            } 
            map[s[r]]=r;
            ans=max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};