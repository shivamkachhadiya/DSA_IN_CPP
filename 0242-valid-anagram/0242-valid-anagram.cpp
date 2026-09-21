class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int>map;
        for(int i=0;i<s.size();i++){
            map[s[i]]++;
        }
        for(int i=0;i<t.size();i++){
            if(map.find(t[i])!=map.end()){
                map[t[i]]--;
                if(map[t[i]]==0){
                    map.erase(t[i]);
                }
            }
            else return false;
        }
        return map.empty();
        
    }
};