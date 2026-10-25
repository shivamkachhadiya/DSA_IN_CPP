class Solution {
public:
    [[nodiscard]] int lengthOfLongestSubstring(const string &s) {
        size_t left=0;
        size_t maxAns=0;
        
        unordered_map<char,int>map;
        int n=s.size();
        map.reserve(n);
        for(size_t right=0;right<s.size();right++){

            while(map.find(s[right])!=map.end()){
                maxAns=max(maxAns,right-left);
                map.erase(s[left]);
                left++;             
            }
            map[s[right]]=right;
            maxAns=max(maxAns,right-left+1);
        }

        return static_cast<int>(maxAns);
    }
};