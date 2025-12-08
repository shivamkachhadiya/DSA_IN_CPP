class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int> map1;
        map<char, int> map2;
        for (int i = 0; i < s.size(); i++) {
            map1[s[i]]++;
        }
        for (int j = 0; j < t.size(); j++) {
            map2[t[j]]++;
        }
        if (map1 == map2) {
            return true;
        }
        return false;
    }
};