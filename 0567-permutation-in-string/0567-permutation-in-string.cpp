class Solution {
public:
    unordered_map<char, int> map;

    bool isValid(string& temp) {
        unordered_map<char, int> freq2;
        for (char c : temp)
            freq2[c]++;
        return map == freq2; // proper frequency match
    }
    bool checkInclusion(string s1, string s2) {
        for (int i = 0; i < s1.size(); i++) {
            map[s1[i]]++;
        }
        int left = 0, right = s1.size()-1;
        while (right < s2.size()) {
           
            string temp = s2.substr(left, s1.size());
            if (isValid(temp)) {
                return true;
            }
            left++;
            right++;
        }
        return false;
    }
};