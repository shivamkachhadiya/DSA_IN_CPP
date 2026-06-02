class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> arr;
        for (int x : nums) arr.push_back(to_string(x));
        
        // custom sort: agar a+b > b+a to a pehle
        sort(arr.begin(), arr.end(), [](string &a, string &b) {
            return a + b > b + a;
        });
        
        if (arr[0] == "0") return "0"; // sab zero case
        
        string res;
        for (auto &s : arr) res += s;
        return res;
    }
};
