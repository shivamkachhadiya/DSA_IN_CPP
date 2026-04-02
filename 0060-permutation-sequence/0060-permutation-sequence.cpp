class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> numbers;
        int factorial = 1;
        for (int i = 1; i < n; i++) {
            factorial *= i;
            numbers.push_back(i);
        }
        numbers.push_back(n);

        string result = "";
        k--;

        while (true) {
            result += to_string(numbers[k / factorial]);
            numbers.erase(numbers.begin() + (k / factorial));
            if (numbers.size() == 0) break;
            
            k %= factorial;
            factorial /= numbers.size();
        }

        return result;
    }
};