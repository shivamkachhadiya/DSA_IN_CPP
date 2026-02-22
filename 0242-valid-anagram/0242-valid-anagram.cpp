class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int>freq1;
        unordered_map<char,int>freq2;
        
        int si=s.size();
        int n=t.size();
        if(si!=n)return false;


        for(auto ch:s){
            freq1[ch]++;
        }
         for(auto ch:t){
            freq2[ch]++;
        }
     
        if(freq1==freq2)return true;
        return false;
    }
};