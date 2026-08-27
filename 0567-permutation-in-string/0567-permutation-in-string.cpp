class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        sort(s1.begin(), s1.end());   // sort s1 once
        int n = s1.size();
        int m = s2.size();

        int left = 0, right = 0;

        while(right < m) {
            // jab tak window size < n hai, expand karo
            if(right - left + 1 < n) {
                right++;
                continue;
            }

            // jab window size == n ho jaaye
            string temp = s2.substr(left, n);
            sort(temp.begin(), temp.end());
            if(temp == s1) return true;

            // window slide karo
            left++;
            right++;
        }

        return false;
    }
};
