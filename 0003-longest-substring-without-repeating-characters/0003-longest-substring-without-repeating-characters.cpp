class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left=0;
        int maxAns=0;
        int currLen=0;

        unordered_map<char,int>map;
        for(int right=0;right<s.size();right++){

            while(map.find(s[right])!=map.end()){
                maxAns=max(maxAns,right-left);
                map.erase(s[left]);
                left++;             
            }
            map[s[right]]=right;
            maxAns=max(maxAns,right-left+1);
        }

        return maxAns;
    }
};