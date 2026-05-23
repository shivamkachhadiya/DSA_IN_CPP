//created 17/03/2026
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> mp;
        vector<string> res;
        int n = s.size();
        for (int i = 0; i + 10 <= n; i++) {
            string sub = s.substr(i, 10);
            if (++mp[sub] == 2) res.push_back(sub);
        }
        return res;
    }
};
