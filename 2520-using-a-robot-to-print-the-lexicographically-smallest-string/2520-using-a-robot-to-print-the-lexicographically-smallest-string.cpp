class Solution {
public:
    string robotWithString(string s) {
        int n = s.size();
        vector<char> suffixMin(n);
        suffixMin[n - 1] = s[n - 1];

        // Preprocess suffix minimums
        for (int i = n - 2; i >= 0; --i) {
            suffixMin[i] = min(s[i], suffixMin[i + 1]);
        }

        string t, result;
        for (int i = 0; i < n; ++i) {
            t.push_back(s[i]);

            // Pop from t to result if top of t <= smallest char left in s
            while (!t.empty() && (i == n - 1 || t.back() <= suffixMin[i + 1])) {
                result.push_back(t.back());
                t.pop_back();
            }
        }

        return result;
    }
};
