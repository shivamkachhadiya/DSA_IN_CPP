class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int>freq(23);
        int index_track=0;
        for(int i=0;i<s.size();i++){
           freq[s[i]]++;
        }
        for(int i=0;i<s.size();i++){
            char take=s[i];
            if(freq[take]<=1)return i;
        }
        return -1;
    }
};