class Solution {
public:
    int splitNum(int num) { // t.c - 0(n log n)-> sorting, s.c - 0(n)-> vector digit array
        vector<int> digits;

        while (num > 0) {
            digits.push_back(num % 10); // get last digit
            num /= 10; // remove last digit
        }

        sort(digits.begin(), digits.end());

        int num1 = 0, num2 = 0;

        for (int i = 0; i < digits.size(); i++) {
            if (i % 2 == 0)
                num1 = num1 * 10 + digits[i]; // if num = 2, than 2 * 10 + 4 = 24 also Because multiplying by 10 shifts the existing number one digit to the left.
            else
                num2 = num2 * 10 + digits[i]; // Because multiplying by 10 shifts the existing number one digit to the left.
        }

        return num1 + num2;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna