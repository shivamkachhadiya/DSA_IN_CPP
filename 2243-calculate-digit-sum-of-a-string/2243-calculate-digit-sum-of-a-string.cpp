class Solution {
public:
    string digitSum(string s, int k) {
        string b;
        while (s.size() > k) {
            b.clear();
            int sum = 0, count = 0;
            
            for (char c : s) {
                sum += c - '0';
                count++;
                
                if (count == k) {
                    b += to_string(sum);
                    sum = 0;
                    count = 0;
                }
            }
            
            if (count > 0) {
                b += to_string(sum);
            }
            
            s = std::move(b);
        }
        return s;
    }
};