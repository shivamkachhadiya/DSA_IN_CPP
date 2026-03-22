class Solution {
public:
    int maxDistinct(string s) {
        // A set only stores unique elements
        unordered_set<char> distinctChars;
        for (char c : s) {
            distinctChars.insert(c);
        }
        return distinctChars.size();
    }
};