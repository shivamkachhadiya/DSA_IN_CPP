class Solution {
public:
    string removeOccurrences(string s, string part) {
         while (s.length() > 0 && s.find(part) < s.length()) {

            int start = s.find(part);
            int end = part.length();
            s.erase(start, end);
        }

        return s;
    }
};