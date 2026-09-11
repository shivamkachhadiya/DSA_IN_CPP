class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int left=0;
        int count=0;
        unordered_map<char,int>mp;
        for(int right=0;right<n;right++){
            
            if(mp.find(s[right])!=mp.end()){
                 left=max(left,mp[s[right]]+1);
                mp[s[right]]=right;
               
            }
            mp[s[right]]=right;
            count=max(count,right-left+1);
        }
        return count;
    }
};