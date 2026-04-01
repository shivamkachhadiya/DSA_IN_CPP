class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int n = words.size();
        int i = 0;

        while (i < n) {
            int j = i;
            int lineLen = 0;

            // Determine how many words fit
            while (j < n && lineLen + words[j].size() + (j - i) <= maxWidth) {
                lineLen += words[j].size();
                j++;
            }

            int gaps = j - i - 1;
            string line;

            // Last line or single word
            if (j == n || gaps == 0) {
                for (int k = i; k < j; k++) {
                    line += words[k];
                    if (k < j - 1) line += " ";
                }
                line += string(maxWidth - line.size(), ' ');
            }
            else {
                int spaces = (maxWidth - lineLen) / gaps;
                int extra = (maxWidth - lineLen) % gaps;

                for (int k = i; k < j; k++) {
                    line += words[k];
                    if (k < j - 1) {
                        line += string(spaces + (k - i < extra ? 1 : 0), ' ');
                    }
                }
            }

            result.push_back(line);
            i = j;
        }

        return result;
    }
};