class Solution {
public:
    // bool checkPalindrome(string &s){
    //     if(s.size()==0)return true;
    //     int n=s.size();
    //     int start=0;
    //     int end=n-1;
    //     while(start<=end){
    //         if(s[start]!=s[end])return false;
    //         start++;
    //         end--;
    //     }
    //     return true;
    // }
    bool isPalindrome(string s) {
        string toLower = "";
        int n=s.size();
        toLower.reserve(n);
        for (int i = 0; i < s.size(); i++) {
            char curr_char = s[i];
            if (isalnum(curr_char)) {
                char to_lower = tolower(curr_char);
                toLower.push_back(to_lower);
            }
        }
        auto checkPalindrome = [&](string& s) {
            if (s.size() == 0)
                return true;
            int n = s.size();
            int start = 0;
            int end = n - 1;
            while (start <= end) {
                if (s[start] != s[end])
                    return false;
                start++;
                end--;
            }
            return true;
        };
        return checkPalindrome(toLower);
    }
};