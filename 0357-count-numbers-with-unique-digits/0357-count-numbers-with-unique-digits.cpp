class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        // Digits sirf 0–9 hain 11 digits ka number unique ho hi nahi sakta if
        if(n > 10) { return countNumbersWithUniqueDigits(10); }

        // base case
        if (n == 0) {
            return 1;
        }

        // for ex man lo n=3
        //  choice _ _ _
        // pehli choice 0 nahi hoo skata= 1-9 = 9
        // dusri choice 0-9 but pehli choice exclude = 9
        // tisri choice  2 digit hoo chuke = 8
        int uniquenumbers_len_n = 9;
        int available_digits = 9;

        // Multiply for the remaining positions (n-1 positions)
        // Example for n=3: 9 * 9 * 8
        for (int i = 0; i < n - 1; i++) {
            uniquenumbers_len_n *= available_digits;
            available_digits--;
        }

        // recursive call kyu?
        // n = 3 ka answer =
        // 1-digit unique numbers
        // 2-digit unique numbers
        // 3-digit unique numbers
        return countNumbersWithUniqueDigits(n - 1) + uniquenumbers_len_n;
    }
};


//recursive dry run
// Dry Run: n = 2
// Step 1:
// unique length 2 = 9 × 9 = 81

// Step 2:
// countNumbersWithUniqueDigits(1) = 10

// Final:
// 10 + 81 = 91

// Dry Run: n = 3
// unique length 3 = 9 × 9 × 8 = 648
// countNumbersWithUniqueDigits(2) = 91


// Final:

// 648 + 91 = 739